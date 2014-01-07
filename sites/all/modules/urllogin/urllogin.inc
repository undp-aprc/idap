<?php
/**
 * @file
 * Include file for page callbacks.
 */

include 'urllogin_security.inc';

/**
 * Administration form.
 */
function urllogin_admin_settings() {
  $form['encryption'] = array(
    '#type' => 'fieldset',
    '#title' => t('Encryption settings'),
    '#description' => '<p>' . t('This page contains all the settings for urllogin.
      However you will also need to add the "login via url" permission to the roles of all users who will
      use this module for logging in.') . '</p><p>'
      . t('For testing purposes, individual url login strings can be generated from') . ' '
      . l(t('the status page - see this page for details.'), 'urllogin/status') . '</p>',
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  $form['encryption']['urllogin_passphrase'] = array(
    '#type' => 'textfield',
    '#title' => t('Pass phrase'),
    '#description' => t('The passphrase for encoding URL access'),
    '#default_value' => variable_get('urllogin_passphrase', 'change this to your passphrase'),
    '#size' => 40,
  );
  $form['encryption']['urllogin_add_dbpass'] = array(
    '#type' => 'checkbox',
    '#title' => t('Append database access string to passphrase'),
    '#description' => t('Increase security by appending the database access string to the passphrase.
       The only disadvantage is that changing your database password will invalidate all currently
       issued URL access strings. The best solution is to set the password in settings.php.'),
    '#default_value' => variable_get('urllogin_add_dbpass', 0),
  );
  if (isset($GLOBALS['urllogin_passphrase'])) { // disable if passphrase set in settings.php
    $form['encryption']['urllogin_add_dbpass']['#disabled'] = TRUE;
    $form['encryption']['urllogin_passphrase']['#disabled'] = TRUE;
    $form['encryption']['urllogin_passphrase']['#title'] = 'Passphrase (not currently used)';
    $form['encryption']['urllogin_passphrase']['#description'] = 'Passphrase has been set in settings.php and overrides this value';
  }
  $form['encryption']['urllogin_codekey'] = array(
    '#type' => 'textfield',
    '#title' => t('Validation number for generating new URL login strings'),
    '#description' => t('A value between 0 and 2,000,000,000. Suggestion: use current date in yyyymmdd format.'),
    '#default_value' => variable_get('urllogin_codekey', 20110531),
    '#size' => 10,
  );
  $form['encryption']['urllogin_codemin'] = array(
    '#type' => 'textfield',
    '#title' => t('Minimum validation number allowed for valid login'),
    '#description' => t('A value between 0 and 2,000,000,000. Suggestion: use oldest valid date in yyyymmdd format.'),
    '#default_value' => variable_get('urllogin_codemin', 20110531),
    '#size' => 10,
  );
  $form['userlist'] = array(
    '#type' => 'fieldset',
    '#title' => t('Bulk generation of access URLs'),
    '#description' => '<p>' . t('A bulk download of all user logon strings as a tab-separated csv file can be downloaded
      by right-clicking and saving ') . l(t('this link'), 'urllogin/userlist.csv') . '.</p><p>'
      . t('But first set the following options (if required) and <strong><em>save the form</em></strong>.') . '</p>',
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  $form['userlist']['urllogin_destination'] = array(
    '#type' => 'textfield',
    '#title' => t('Optional destination for bulk generated links'),
    '#description' => t('No leading "/" e.g. blog/my_latest_article'),
    '#default_value' => variable_get('urllogin_destination', ''),
    '#size' => 50,
  );
  $form['userlist']['urllogin_useprofile'] = array(
    '#type' => 'hidden', /* marked hidden until profiles are supported properly in D7 (see end of file) */
    '#title' => t('use "firstname" and "lastname" fields from profile when creating downloaded user list'),
    '#description' => t('Requires the profile module and the creation of fields with the exact names:
       <em>profile_firstname, profile_lastname</em>.'),
    '#default_value' => variable_get('urllogin_useprofile', 0),
  );
  return system_settings_form($form);
}

/**
 * Validate the urllogin configuration form.
 */
function urllogin_admin_settings_validate($form, $form_state) {
  $entry = $form_state['values']['urllogin_codekey'];
  if (preg_match('@^[0-9]+$@', trim($entry)) != 1) { // test for digits
    form_set_error('urllogin_codekey', t('Please enter a positive integer.'));
  }
  $entry = $form_state['values']['urllogin_codemin'];
  if (preg_match('@^[0-9]+$@', trim($entry)) != 1) { // test for digits
    form_set_error('urllogin_codemin', t('Please enter a positive integer.'));
  }
}

/**
 * Displays status page and allows a URL string to be generated for test purposes.
 *
 * @param $testuid
 *   Optional UID for generating a test URL login string
 *
 * @return
 *   Page containing test results
 */
function urllogin_status_page($testuid = 0) {
  $uid = (int)$testuid; //this will sanitize it as well
  if (isset($GLOBALS['urllogin_passphrase'])) { // first see if it is in settings.php
    $passkey = 'set from settings.php';
  }
  else {
    $passkey = variable_get('urllogin_passphrase', 'no passphrase defined');
    if (variable_get('urllogin_add_dbpass', '0') != 0) {
      // we don't really want to give away the actual database access string
      $passkey .= ' + database string';
    }
  }
  $codekey = variable_get('urllogin_codekey', 0);
  $codemin = variable_get('urllogin_codemin', 0);
  $page = '<h2> ' . urllogin_help('admin/help#checkin', 0) . '</h2><ul>';
  $page .= '<li>' . t('Test UID') . ': ' . $uid . '</li>';
  $page .= '<li>' . t('Passphrase') . ': ' . $passkey . '</li>';
  $page .= '<li>' . t('Current Validation number') . ': ' . $codekey . '</li>';
  $page .= '<li>' . t('Minimum validation number') . ': ' . $codemin . '</li>';
  $urlstr = urllogin_encode($uid, $codekey, urllogin_passphrase());
  $page .= '<li>' . t('Encoded URL access string: [') . $urlstr . ']</li>';
  $page .= '</ul>';
  $testlink = 'l_test/' . $urlstr;
  $page .= '<p>' . t('This page can be used to generate individual access strings for testing purposes.
    Simply add the UID of the user to the end of the url for this page, revisit the page and the
    access string will be displayed above.') . '</p><p>'
   . t('To test the access string, use') . ' ' . l(t('the test page'), 'l_test/') . ' '
   . t('by appending the access string to it, e.g.:') . ' '
   . l($testlink, $testlink) . '</p>';
  return $page;
}

/**
 * Tests to see if UID can be logged on.
 *
 * @param $uid
 *   UID to be tested
 *
 * @param $resultmsg
 *   Contains resultmsg message if function fails.
 *
 * @return
 *   If sucessful, loaded account of user
 *   Else NULL
 */
function _urllogin_testuid($uid, &$resultmsg) {
  if ($uid < 2) {
    $resultmsg = t('UID is %uid - cannot login as user 0 or 1', array('%uid' => $uid));
    return NULL;
  }
  $account = user_load($uid);
  if (!$account) {
    $resultmsg = t('User %uid does not exist', array('%uid' => $uid));
    return NULL;
  }
  if (!user_access('login via url', $account)) {
    $resultmsg = t('User %uid denied access', array('%uid' => $uid));
    return NULL;
  }
  $resultmsg = t('User %username (%uid) successfully validated',
    array('%username' => $account->name, '%uid' => $uid));
  return $account;
}

/**
 * Diagnostic test page for setting up urllogin urls.
 *
 * @param $urlstring
 *   login string from URL
 *
 * @return
 *   Page containing test results
 */
function urllogin_test_page($urlstring = 'none') {
  $urlstr = check_plain($urlstring); // sanitize
  $page = "<ul><li>Initial URL string = [$urlstr]</li>";
  $resultmsg = "";
  $uid = urllogin_decode($urlstr,
    variable_get('urllogin_codekey', 20110531),
    variable_get('urllogin_codemin', 20110531),
    urllogin_passphrase(), $resultmsg);
  if ($uid > -1) {
    $account = _urllogin_testuid($uid, $resultmsg);
  }
  else {
    $account = NULL;
  }
  if ($account != NULL) {
    // find where to go: get rid of first two arguments and use the rest of the URL as the destination
    $args = arg();
    unset($args[0]);
    unset($args[1]);
    $goto = implode('/', $args);

    // maintain the original query string
    $query = $_GET;
    unset($query['q']);
    if (count($query) > 0) {
      $goto .= '?' . implode('&', $query);
    }

    // Check in case this user is already logged in
    global $user;
    $logged_in = ($user->uid == $uid);
    if ($logged_in) {
      $resultmsg = t('User %username (%uid) was already logged in. Redirected to: %goto',
        array('%username' => $account->name, '%uid' => $uid, '%goto' => $goto));
    }
    else {
      $resultmsg = t('Logging in as %username (%uid). Redirected to: %goto',
        array('%username' => $account->name, '%uid' => $uid, '%goto' => $goto));
      $logged_in = TRUE; // assume success
    }
    if ($logged_in) {
      // get rid of first two arguments and use the rest of the URL as the destination
      $page .= "<li>$resultmsg</li><li>goto: $goto</li></ul>";
      return $page;
    }
  }
  $page .= "<li>$resultmsg</li></ul>";
  return $page;
}

/**
 * This is the function that actually performs the login.
 *
 * @param $urlstring
 *   login string from URL
 *
 * The function first validates the URL login string.
 * If good, then the user is logged in and transferred to the destination page.
 * Otherwise they are taken to the front page.
 * Results, good or bad, are logged with watchdog.
 */
function urllogin_link_page($urlstring = 'none') {
  $urlstr = check_plain($urlstring); // sanitize
  $resultmsg = "";
  $uid = urllogin_decode($urlstr,
    variable_get('urllogin_codekey', 20110531),
    variable_get('urllogin_codemin', 20110531),
    urllogin_passphrase(), $resultmsg);
  if ($uid > -1) {
    $account = _urllogin_testuid($uid, $resultmsg);
  }
  else {
    $account = NULL;
  }
  //watchdog('urllogin', $resultmsg, array(), WATCHDOG_DEBUG);
  if ($account != NULL) {
    // find where to go: get rid of first two arguments and use the rest of the URL as the destination
    $args = arg();
    unset($args[0]);
    unset($args[1]);
    $goto = implode('/', $args);

    // maintain the original query string
    $query = $_GET;
    unset($query['q']);
    if (count($query) > 0) {
      $goto .= '?' . implode('&', $query);
    }

    // Check in case this user is already logged in
    global $user;
    $logged_in = ($user->uid == $account->uid);
    if ($logged_in) {
      $resultmsg = t('User %username (%uid) was already logged in. Redirected to: %goto',
        array('%username' => $account->name, '%uid' => $uid, '%goto' => $goto));
      watchdog('urllogin', $resultmsg, array(), WATCHDOG_NOTICE);
    }
    else {
      $form_state['uid'] = $account->uid;
      $logged_in = user_login_submit(array(), $form_state);
      if ($logged_in) {
      $resultmsg = t('Logging in as %username (%uid). Redirected to: %goto',
        array('%username' => $account->name, '%uid' => $uid, '%goto' => $goto));
        watchdog('urllogin', $resultmsg, array(), WATCHDOG_INFO);
        // if persistent_login is installed, then set "remember me"
        if (module_exists('persistent_login')) {
          _persistent_login_create_cookie($account);
        }
      }
      else {
        $resultmsg = t('Failed login as %username (%uid)',
          array('%username' => $account->name, '%uid' => $uid));
      }
    }
    if ($logged_in) {
      drupal_goto(implode('/', $args), $query);
    }
  }
  watchdog('urllogin', $resultmsg, array(), WATCHDOG_WARNING);
  if ($uid == -2) {
    return '<h1>' . t('The link you used to access this page has expired.') . '</h1>' .
    '<p>' . t('If you have created a password, you can log on') . ' ' . l(t('here'), 'user') . '.</p>';
  }
  else {
    drupal_goto('');
  }
}

/**
 * Link to download of user access URL's as a csv.
 * A theme template file is needed of the page-urllogin-userlist.csv.tpl
 * containing the single line: < ?php print $content; ? >
 *
 * @todo test whether profile module is installed and if fields are correct
 * @todo look at integrating with content profile module
 *
 * @return
 *   Page containing user access URL's as a file of tab separated variables
 */
function urllogin_userlist_page() {
  $codekey = variable_get('urllogin_codekey', 0);
  $passphrase = urllogin_passphrase();
  $thissite = url('l/', array('absolute' => TRUE));
  $destination = '/' . variable_get('urllogin_destination', '');

  // Tell browser this is not a web page but a file to download.
  drupal_add_http_header('Content-Type', 'text/csv; charset=utf-8');
  drupal_add_http_header('Content-Disposition', 'inline; filename="userlist.csv"');

  // Find out if all authenticated users have the permission and
  // use a different SQL query depending on result.
  $sql = "SELECT permission FROM {role_permission} AS p WHERE rid = 2 AND (p.permission LIKE '%login via url%')";
  if (db_query($sql)->fetchField() == "") {
    $join_user_role = "JOIN {users_roles} AS r ON r.uid = u.uid
                       JOIN {role_permission} AS p ON p.rid = r.rid ";
    $role_has_permission = "AND p.permission LIKE '%login via url%' ";
  }
  else {
    $join_user_role = "";
    $role_has_permission = "";
  }

  // use a different SQL query depending on whether we are to get firstname and lastname from the profile
  if (variable_get('urllogin_useprofile', 0) == 0) {
  $sql = "SELECT u.uid, u.mail, u.name
            FROM {users} AS u "
            . $join_user_role .
           "WHERE u.uid > 1 "
            . $role_has_permission .
           "ORDER BY name";
    $result = db_query($sql);
    print t('UID') . "\t" . t('Name') . "\t" . t('Email') . "\t" . t('URL') . "\r\n";
    foreach ($result as $data) {
      $urlstr = $thissite . urllogin_encode($data->uid, $codekey, $passphrase) . $destination;
      print $data->uid . "\t" . $data->name . "\t" . $data->mail . "\t" . $urlstr . "\r\n";
    }
  }
  else {
/* Profiles need to be reworked significantly
    $sql = "SELECT u.uid, u.mail, u.name, vf.value AS first, vl.value AS last
            FROM {users} AS u "
            . $join_user_role .
           "JOIN {profile_values} AS vf ON vf.uid = u.uid
            JOIN {profile_fields} AS f ON f.fid = vf.fid
            JOIN {profile_values} AS vl ON vl.uid = u.uid
            JOIN {profile_fields} AS l ON l.fid = vl.fid
          WHERE u.uid > 1
            AND f.name = 'profile_firstname'
            AND l.name = 'profile_lastname' "
            . $role_has_permission .
           "ORDER BY last, first";
    $result = db_query($sql);
    print t('UID') . "\t" . t('Name') . "\t" . t('First') . "\t" . t('Last')
          . "\t" . t('Email') . "\t" . t('URL') . "\r\n";
    while ($data = db_fetch_object($result)) {
      $urlstr = $thissite . urllogin_encode($data->uid, $codekey, $passphrase) . $destination;
      print $data->uid . "\t" . $data->name . "\t" . $data->first . "\t" . $data->last
          . "\t" . $data->mail . "\t" . $urlstr . "\r\n";
    }
 */
  }
}


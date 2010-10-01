<?php
/**
 * @file callblast.recordings.inc
 *  callbacks for calblast/recordings
 */
/**
 * 
 */
function callblast_recordings_page() {
  //$header = array('name', 'url', 'number', 'duration', 'uid');
  $header = array('recording', 'by', 'number', 'seconds');

  // data
  $recordings = callblast_get_recordings(); 
  $i = 0; 
  foreach($recordings as $recording) {
    $data[$i]['recording'] = l($recording['name'], $recording['url']);
    $user = user_load($recording['uid']);
    $data[$i]['by'] = l($user->name, "/user/$user->uid");
    $data[$i]['number'] = $recording['number'];
    $data[$i]['seconds'] = $recording['duration'];
    $i++;
  }
  
  // caption
  $caption = t('To listen to recording, click link below. '
              .'Note: This may only work in a Firefox Internet browser. To get '
              .'the recording to play in Chrome, right click, open in a new tab/window, '
              .'delete ".mp3" from the end of the URL, then reload the page. ');
  
  //$output = theme('table', $header, $recordings);
  //$output = theme('table', $header, $data, $caption);
  $output = '';
  $output .= "<p>$caption</p>";
  $output .= theme('table', $header, $data);

  return $output;
}

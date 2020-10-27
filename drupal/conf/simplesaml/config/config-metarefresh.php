<?php
$config = [
  'sets' => [
    'pori' => [
      'cron'      => ['hourly'],
      'sources'   => [
        [
          'src' => 'https://fs.pori.fi/FederationMetadata/2007-06/FederationMetadata.xml',
        ],
      ],
      'expireAfter'       => 60*60*24*4, // Maximum 4 days cache time.
      'outputDir'     => 'metadata/metarefresh-pori/',
      'outputFormat' => 'flatfile',
    ],
  ],
];

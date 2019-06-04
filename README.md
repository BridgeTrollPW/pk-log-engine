# Log-Engine

### Description
At it's core, this is a simple binary that can search and parse loglines from M&B - Warband servers.
There are different Engine Adapters that serve different purposes and handle the logs in different ways.
In general, the log-engine was designed to be used for administrative purposes and to be integrated in a server backend system.
Therefore special care went into performance for log search. If administrative tasks need to be performed in dependency to log file analysis, it should not take long to get the desired data to work with 

## Adapters
### TextSearch
### Categorization
### MultiIPChecker
### ClientUpTime
### OptimizeMe
### PatternAbuser


## Interface
### Input: CLI
`-c , -config`
>This specifies the Configuration File. Best is if you use absolute paths like `-c /srv/www/myServerBackend/log-engine/config.json`

`-f , -function`
>This will reference to the Engine internal functions which is basically only a task execution list for engine adapters. For now the zero means normal text search. `-f 0`

`-l , -log`
>Specifies the path to the server log file. This is also best an absolute path, yet relative paths work just as well.

`-s , -search`
>Specifies a test string of keywords to search for. These should be in the form of `-s keyword1;keyword2;keyword3;keyword4`

`-ls , -lines`
>Specifies to only search between certain line numbers in the format `-ls start;end`

`-pp , -pretty-printing`
>output the json as pretty printed or as raw unformatted json string

`-p , -payload`
>pass additional input to the requested engine adapter. This has to be a specific json string in order for the engine to recognize and parse your input
### Output: JSON

## Implementation Examples
### JavaScript + Nodejs
```objectivec
const { spawn } = require('child_process');
const child = spawn('./log_engine', [
    '-c', 'resources/config.json', 
    '-l', 'resources/logs.txt', 
    '-f', '0', 
    '-s', '2842835;41.248.17.186'
]);

child.stdout.on('data', (data) => {
    console.log(`stdout: ${data}`);
});

child.stderr.on('data', (data) => {
    console.log(`stderr: ${data}`);
});

child.on('close', (code) => {
    console.log(`child process exited with code ${code}`);
});
```

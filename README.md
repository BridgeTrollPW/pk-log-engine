# Log-Engine

### Description
This is a simple binary that can search and parse loglines from M&B - Warband servers. The rules can be added via configuration therefore this can be used for any module.
The default rules are done for the Persistent Kingdoms module

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

`-p , -pretty-printing`
>output the json as pretty printed or as raw unformatted json string
### Output: JSON
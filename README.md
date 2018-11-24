# serverboy
Like websocketed，serverboy is also a tool for indie game developers to develop game server. As long as you can write 
an executeable app (shell, c, c++, go, python, java...) that reads STDIN and writes to STDOUT, serverboy can build a game server for you!

# deps
1. golang (just for running demo)
2. gcc 4.8+
3. uws is already in ./lib (https://github.com/uNetworking/uWebSockets)

# run example
1. cd serverboy/build;cmake..;make;cd bin;./serverboy
2. cd serverboy/demo;go run learn.go
3. open two games in the browser(for example type http://192.168.0.115:8080 twice in browser) 
4. enjoy yourself !

# doc
1. demo


# Stress & benchmarks

broadcast stress: 

    consume 251 us
    consume 451 us
    consume 248 us
    consume 1151 us
    consume 259 us
    consume 788 us
    consume 216 us
    consume 223 us
    consume 460 us
    consume 261 us
    consume 292 us
    consume 241 us
    consume 1126 us
    consume 810 us
    consume 235 us
    consume 1150 us
    consume 422 us
    consume 1002 us
    consume 243 us
    consume 255 us
    consume 383 us
    consume 232 us
    consume 236 us
    consume 292 us
    consume 289 us
    consume 1491 us
    consume 395 us
    consume 284 us
    consume 364 us
    consume 817 us
    consume 244 us
    consume 261 us
 

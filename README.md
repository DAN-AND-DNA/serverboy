# serverboy
Like websocketed，serverboy is also a tool for indie game developers to develop game server. As long as you can write 
an executeable app (shell, c, c++, go, python, java...) that reads STDIN and writes to STDOUT, serverboy can build a game server for you!

# deps
1. golang (just for running demo)
2. gcc 4.8+
3. uws is already in ./lib (https://github.com/uNetworking/uWebSockets)

# run example
1. cd serverboy/build;cmake..;make;cd bin;./demo
2. cd serverboy/demo;go run learn.go
3. open two games in the browser(for example type http://192.168.0.115:8080 twice in browser) 
4. enjoy yourself !

# doc
1. demo


# benchmarks


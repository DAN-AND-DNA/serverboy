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


# example Stress

broadcast stress: 
 
    cosume 157 us
    cosume 190 us
    cosume 150 us
    cosume 847 us
    cosume 177 us
    cosume 161 us
    cosume 119 us
    cosume 170 us
    cosume 454 us
    cosume 518 us
    cosume 457 us
    cosume 262 us
    cosume 586 us
    cosume 661 us
    cosume 989 us
    cosume 216 us
    cosume 303 us
    cosume 250 us
    cosume 172 us
    cosume 153 us
    cosume 441 us
    cosume 151 us
    cosume 571 us
    cosume 331 us
    cosume 249 us
    cosume 118 us
    cosume 204 us
    cosume 189 us
    cosume 145 us
    cosume 170 us
    cosume 152 us
    cosume 155 us
    cosume 452 us
    cosume 121 us
    cosume 196 us
    cosume 496 us
    cosume 353 us
    cosume 947 us
    cosume 548 us
    cosume 934 us
    cosume 144 us
    cosume 521 us
    cosume 117 us
    cosume 677 us
    cosume 143 us
 

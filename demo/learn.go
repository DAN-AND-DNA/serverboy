package main

import (
	"github.com/gin-gonic/gin"
)

func CORS() gin.HandlerFunc {
	return func(context *gin.Context) {
		context.Writer.Header().Add("Access-Control-Allow-Origin", "*")
		context.Writer.Header().Add("Access-Control-Allow-Headers", "Content-Type")
		context.Writer.Header().Add("Access-Control-Request-Method", "POST")
		context.Writer.Header().Add("Access-Control-Request-Method", "GET")

		if context.Request.Method == "OPTIONS" {
			context.AbortWithStatus(204)
		} else {
			context.Next()
		}
	}
}

func main() {

	router := gin.Default()
	router.Use(CORS())

	router.StaticFile("/", "./index.html")
	router.Static("/assets", "./assets")
	router.Static("/js", "./js")

	router.Run(":8080")
}

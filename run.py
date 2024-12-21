import http.server
import socketserver

PORT = 8000
Handler = http.server.SimpleHTTPRequestHandler

with socketserver.TCPServer(("", PORT), Handler) as httpd:
    print("Running at http://localhost:{}/jumpThingy.html".format(PORT))
    try:
        httpd.serve_forever()
    except KeyboardInterrupt:
        print("^C received, shutting down the web server")
        httpd.socket.close()

import os
import requests
from flask import Flask, request

app = Flask(__name__)
host = os.environ['HOST']

@app.route('/', defaults={'path': ''})
@app.route('/<path:path>')
def catch_all(path):
    url = "http://" + host + "/" + path
    return requests.get(url).text

if __name__ == '__main__':
    app.run(host= '0.0.0.0')

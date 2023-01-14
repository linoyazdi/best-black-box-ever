from flask import Flask
from flask import send_file
import sys
import argparse


app = Flask('download file')
GLOBALS = {}


def parse_arguments():
	parser = argparse.ArgumentParser()
	parser.add_argument('--path', type=str, required=True)
	parser.add_argument('--port', default=5000, type=int)
	args = parser.parse_args()
	return args.path, args.port

	
@app.route('/')
def download_file():
	return send_file(GLOBALS['path'], as_attachment=True)

	
if __name__ == '__main__':
	path, port = parse_arguments()
	GLOBALS['path'] = path
	app.run(port=port)
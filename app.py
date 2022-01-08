from flask import Flask
from flask import render_template

app = Flask(__name__)

@app.route('/')
def home():
    return render_template('index.html', 
        text="Mon premier essai gitpod", couleur='red')

app.run(host='0.0.0.0', port=3000)


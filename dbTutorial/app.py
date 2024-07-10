from flask import Flask, render_template, request, session, redirect, url_for
from flask_mysqldb import MySQL

app = Flask(__name__)

app.secret_key='kmorale3'
app.config['MYSQL_HOST'] = 'localhost'
app.config['MYSQL_USER'] = 'kmorale3'
app.config['MYSQL_PASSWORD'] = 'goirish'
app.config['MYSQL_DB'] = 'kmorale3'

mysql = MySQL(app)

@app.route('/')
def home():
   return "hello world!"

@app.route('/index,',methods=['GET','POST'])
def index():
    if request.method == 'POST':
        age = request.form['age']
        name = request.form['name']
        cursor = mysql.connection.cursor()
        cursor.execute("insert into age (name, age) values (%s,%s)", (name, age))
        mysql.connection.commit()
        cursor.execute("select name, age from age")
        age_data = cursor.fetchall()
    return render_template('index.html', data=age_data)

if __name__ == '__main__':
   app.debug = True
   app.run(host='db8.cse.nd.edu', port=5047)
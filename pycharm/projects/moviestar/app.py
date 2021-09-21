from pymongo import MongoClient

from flask import Flask, render_template, jsonify, request

app = Flask(__name__)

client = MongoClient('localhost', 27017)
db = client.dbsparta

# HTML 화면 보여주기
@app.route('/')
def home():
    return render_template('index.html')

# API 역할을 하는 부분
@app.route('/api/list', methods=['GET'])
def show_stars():
    mystars = list(db.mystar.find({}, {'_id': 0}).sort('like',-1))
    return jsonify({'result': 'success', 'mystars': mystars})

@app.route('/api/like', methods=['POST'])
    # 1. 클라이언트가 전달한 name_gids=['POST'])
def like_star():
    name_receive = request.form['name_give']
    star = db.mystar.find_one({'name': name_receive})
    new_like =star['like']+1

    db.mystar.update_one({'name': name_receive}, {'$set': {'like': new_like}})

    return jsonify({'result': 'success', 'msg': '좋아요 완료'})

@app.route('/api/delete', methods=['POST'])
def delete_star():
    # 1. 클라이언트가 전달한 name_give를 name_receive 변수에 넣습니다.
    # 2. mystar 목록에서 delete_one으로 name이 name_receive와 일치하는 star를 제거합니다.
    # 3. 성공하면 success 메시지를 반환합니다.
    return jsonify({'result': 'success', 'msg': 'delete 연결되었습니다!'})

if __name__ == '__main__':
    app.run('0.0.0.0', port=5000, debug=True)
# Facebookのいいね数を取得するプログラム

# モジュールの読み込み
require 'open-uri' #指定したURLにアクセスして、一時的なファイルを作り実行結果を保存する
require 'json' #json形式を扱うモジュール

class FbShareCounter
  BASE_URL = 'http://graph.facebook.com/?id='  #FacebookグラフAPIのURL


  # イイネ数のカウント対象URlを指定
  def initialize(target_url)
    @request_url = BASE_URL + target_url
  end

# 算出処理のメソッド
  def count
    response = open(@request_url).read #グラフAPIにアクセスして文字列データを取得
    hash = JSON.parse(response) #文字列データ（JSON）をハッシュにする
    hash['share']['share_count'] #ハッシュからいいね数を取得
  end
end

counter = FbShareCounter.new('http://gihyo.jp')
counter2 = FbShareCounter.new('https://ja-jp.facebook.com/Ochyai')

p counter.count
p counter2.count

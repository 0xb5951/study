#rubyでのファイル入出力

file_path = 'sample.txt'

# 書き込み
open(file_path, 'w') do |f|
  f.puts('Hello,World!')
end

# 読み込み
open(file_path, 'r') do |f|
  p f.read
end

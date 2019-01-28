#!/usr/bin/env ruby
pinyin = %w{ling yi er san si wu liu qi ba jiu}
str = gets
result = str.each_char.inject(0){|sum, c| sum += c.to_i}
puts result.to_s.each_char.map{ |c| pinyin[c.to_i] }.join(' ')


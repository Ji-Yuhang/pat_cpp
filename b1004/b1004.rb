#!/usr/bin/env ruby

n = gets.to_i

datas = []
n.times do
  line = gets
  name, id, score = line.split.map(&:strip)
  datas.push({name: name, id: id, score: score.to_i})
end
max_data = datas.max{|d1, d2| d1[:score] <=> d2[:score]}
min_data = datas.min{|d1, d2| d1[:score] <=> d2[:score]}
puts max_data[:name] + " "+ max_data[:id]
puts min_data[:name] + " "+ min_data[:id]

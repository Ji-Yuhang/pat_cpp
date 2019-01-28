#!/usr/bin/env ruby
require 'set'
gets
numbers = gets.split.map(&:to_i).to_set

result = numbers

# 子空间
#set = Set.new 
numbers.each do |number|
  n = number
  while(n > 1) do
    if n % 2 == 0
      n = n / 2
    else
      n = (3 * n + 1) / 2
    end
    #result.delete number if result.include? n
    result.delete n
    #set.add n
  end
end

#result = numbers - set
puts result.to_a.reverse.join(' ')


#!/usr/bin/env ruby
require 'prime'
n = gets.to_i
primes = Prime.each(n).to_a 
count = 0
(0...primes.size - 1).each do |i|
  a = primes[i]
  b = primes[i+1]
  #a, b = array.slice(i,2)
  count += 1 if b - a == 2
  #puts "#{a} , #{b}" if b - a == 2
end
puts count


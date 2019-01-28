#!/usr/bin/env ruby
require 'profile'
require 'set'
def find_primes(n)
  #@primes = Set.new
  results = Array.new n, true
  #results = (2..n).to_set
  (2..n/2).each do |i|
    (2..n/2).each do |j|
      temp = i * j
      next if !results[temp]
      results[temp] = false
      #results.delete temp
      #break if temp > n
    end
  end
  @primes = []
  (2..n).each{|i| @primes.push i if results[i]}
  @primes
end

def main
  n = gets.to_i
  primes = find_primes(n)
  array = primes.to_a
  puts array
  count = 0
  (0...array.size - 1).each do |i|
    a = array[i]
    b = array[i+1]
    #a, b = array.slice(i,2)
    count += 1 if b - a == 2
    #puts "#{a} , #{b}" if b - a == 2
  end
  puts count
end

main

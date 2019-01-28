#!/usr/bin/env ruby

n = gets.to_i
#puts n
count = 0
while n > 1 do
  if n % 2 == 0
    n = n / 2 
  else
    n = (3*n+1) / 2
  end
  count += 1
  #puts n
  #break if n == 1
end
puts count

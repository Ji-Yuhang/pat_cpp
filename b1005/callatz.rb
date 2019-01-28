#!/usr/bin/env ruby
require 'set'
n = ARGV[0].to_i
set = Set.new 
set.add n
while(n > 1) do
  if n % 2 == 0
    n = n / 2
  else
    n = (3 * n + 1) / 2
  end
  set.add n
end
puts set


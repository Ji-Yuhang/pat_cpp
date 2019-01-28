#!/usr/bin/env ruby
padded_str = "000"+gets.strip
three_char = padded_str[-3..-1]
i,j,k = three_char.each_char.map &:to_i
i.times {putc 'B'}
j.times {putc 'S'}
(1..k).each{|i| putc i.to_s}
#puts padded_str
#puts three_char
#puts i
#puts j
#puts k

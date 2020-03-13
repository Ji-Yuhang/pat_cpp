#!/usr/bin/env ruby
# 1019 General Palindromic Number (20分)

# 27 2
# Yes
# 1 1 0 1 1

# 121 5
# No
# 4 4 1

$DEBUG = false

def test_case
  [
    [27, 2],
    [121, 5],
  ]
end

def build_input
  if $DEBUG
    test_case.last
  else
    gets.split.map(&:to_i)
  end
end

number, base = build_input
puts "number: #{number}, base: #{base}" if $DEBUG

result = []
temp = number
index = 1
while temp != 0
  # a = base ** index
  remain = temp / base
  c = temp % base
  result.unshift c
  puts "remain: #{remain}, c: #{c}, temp: #{temp}" if $DEBUG
  temp = remain
  sleep 1 if $DEBUG
end
puts result.reverse == result ? "Yes" : "No"
print result.join(" ")

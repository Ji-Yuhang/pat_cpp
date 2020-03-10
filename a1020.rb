# A1020.rb
# 7
# 2 3 1 5 7 6 4
# 1 2 3 4 5 6 7
N = gets
def post_order
  # %w{2 3 1 5 7 6 4}
  gets.split(' ')
end

def in_order
  # %w{1 2 3 4 5 6 7}
  gets.split(' ')
end

class Node
  attr_accessor :root, :parent
  attr_accessor :left_node, :right_node
  attr_accessor :done
end

def split_to_left_right(node, sub_post_order, sub_in_order)
  root = sub_post_order[-1]
  node.root = root
  node.done = false
  if sub_post_order.size <= 0 ||sub_in_order.size <= 0
    node.done = true
    parent = node
    while(parent) do
      parent.done = true
      parent = parent.parent
    end
    return
  end

  root_index = sub_in_order.index(root)
  inorder_left = sub_in_order[0..root_index-1]
  inorder_right = sub_in_order[root_index+1..-1]
  
  inorder_left = [] if root_index == 0
  inorder_right = [] if root_index == sub_in_order.size - 1

  
  # puts "root: #{root}"
  # puts "inorder left: #{inorder_left}"
  # puts "inorder right: #{inorder_right}"
  # puts "----------------"

  postorder_left = sub_post_order[0..inorder_left.size - 1]
  postorder_right = sub_post_order[inorder_left.size..-2]
  postorder_left = [] if root_index == 0
  postorder_right = [] if root_index == sub_in_order.size - 1


  # puts "postorder_left left: #{postorder_left}"
  # puts "postorder_left right: #{postorder_right}"
  # puts "----------------"

  [root, inorder_left, inorder_right, postorder_left, postorder_right]

  # sleep(1)
  left_node = Node.new
  left_node.parent = node
  left_node.done = false
  node.left_node = left_node

  right_node = Node.new
  right_node.parent = node
  right_node.done = false
  node.right_node = right_node

  split_to_left_right(left_node, postorder_left, inorder_left)
  split_to_left_right(right_node, postorder_right, inorder_right)

end

node = Node.new
node.parent = nil
node.done = false
root, left, right, postorder_left, postorder_right = split_to_left_right(node, post_order, in_order)
# puts node
queue = []
level_nodes = [node].compact

while !level_nodes.empty? do
  queue += level_nodes.map{|n| n.root}.compact
  level_nodes = level_nodes.map{|n| [n.left_node, n.right_node]}.flatten.compact
end
printf queue.join(' ')

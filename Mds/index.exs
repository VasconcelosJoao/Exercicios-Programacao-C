defmodule Hello do
  def world do
    IO.puts "Hello World!"
  end

  def greet(name) do
    a=12
    b=2
    IO.puts "Hello, #{name} #{a*b}"
  end


end

Hello.world()
Hello.greet "Joao"

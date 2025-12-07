defmodule Main do
  def start do
    IO.gets("")

    input = 
      IO.read(:stdio, :eof)
      |> String.split()
      |> Enum.map(&String.to_integer/1)

    Enum.chunk_every(input, 2)
    |> Enum.reduce(%{}, fn [x, y], set ->
      Map.put(set, x - y, true)
    end)
    |> map_size()
    |> IO.puts()
  end
end

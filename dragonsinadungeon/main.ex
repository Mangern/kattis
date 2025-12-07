defmodule Main do
  def start do
    [n, m] = 
      IO.gets("")
      |> String.split()
      |> Enum.map(&String.to_integer/1)

    grid = 
      Enum.map(1..n, fn _ ->
        IO.gets("")
        |> String.trim()
        |> String.to_charlist()
        |> List.to_tuple()
      end)
      |> List.to_tuple()

    {sr, sc} =
      Enum.find_value(0..n-1, fn r ->
        row = elem(grid, r)

        case Enum.find_index(0..m-1, fn c ->
          elem(row, c) == ?G
        end) do
          nil -> nil
          c -> {r, c}
        end
      end)
    {x, _} = traverse(grid, n, m, sr, sc, MapSet.new())
    cond do
      x -> IO.puts("YES")
      true -> IO.puts("NO")
    end
  end

  def traverse(grid, n, m, r, c, visited) when r < 0 or n <= r or c < 0 or m <= c do
    {false, visited}
  end
  def traverse(grid, n, m, r, c, visited) do
    cond do
      MapSet.member?(visited, {r, c}) ->
        {false, visited}
      true -> 
        cell = elem(elem(grid, r), c)
        if cell == ?E do
          {true, visited}
        else 
          if cell == ?. or cell == ?G do
            visited = MapSet.put(visited, {r, c})
            neighbors = [{r-1, c-1}, {r-1, c}, {r-1,c+1},
                         {r, c-1},             {r, c+1},
                         {r+1, c-1}, {r+1, c}, {r+1, c+1}]
            Enum.reduce_while(neighbors, {false, visited}, fn {nr, nc}, {_, v} ->
              {found, v2} = traverse(grid, n, m, nr, nc, v)
              if found do
                {:halt, {true, v2}}
              else
                {:cont, {false, v2}}
              end
            end)
          else
            {false, visited}
          end
        end
    end
  end
end

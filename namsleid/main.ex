defmodule Main do
  def start do
    input = IO.read(:stdio, :eof)
      |> String.split()
      |> Enum.map(&String.to_integer/1)
    [n | input] = input
    graph = create_graph(n, input)
      |> List.to_tuple()
    {ret, topo} = runall(1, n, graph, [], %{})
    if not ret do
      IO.puts("Omogulegt!")
    else
      IO.puts("Mogulegt!")
      grouped = Enum.sort(topo)
      |> Enum.group_by(fn {t, u} -> t end)
      |> Map.to_list()

      IO.puts(Enum.count(grouped))

      grouped
      |> Enum.sort()
      |> Enum.map(fn {t, list} -> 
        IO.write(Enum.count(list))
        for {t,u} <- list, do: IO.write(" #{u}")
        IO.write("\n")
      end)
    end
  end

  def create_graph(n, _input) when n == 0 do [] end
  def create_graph(n, input) do
    [m | input] = input
    {neighbors, input} = Enum.split(input, m)
    [neighbors] ++ create_graph(n - 1, input)
  end

  def visit(u, graph, topo, visited_now, visited_all) do
    cond do
      MapSet.member?(visited_now, u) ->
        {false, topo, visited_now, visited_all, 0}
      Map.has_key?(visited_all, u) ->
        {true, topo, visited_now, visited_all, Map.get(visited_all, u)}
      true ->
        # Open set
        visited_now = MapSet.put(visited_now, u)
        neighbors = elem(graph, u - 1)
        {ok, topo, visited_now, visited_all, time} = Enum.reduce_while(
          neighbors, 
          {true, topo, visited_now, visited_all, 0}, 
          fn nei, {_, topo, v, va, time} ->
            {ok, topo2, v2, vall2, time2} = visit(nei, graph, topo, v, va)
            if ok do
              {:cont, {true, topo2, v2, vall2, max(time, time2 + 1)}}
            else
              {:halt, {false, topo2, v2, vall2, 0}}
            end
        end)
        if not ok do
          {false, [], visited_now, visited_all, 0}
        else
          visited_all = Map.put(visited_all, u, time)
          visited_now = MapSet.delete(visited_now, u)
          {true, [{time, u}] ++ topo, visited_now, visited_all, time}
        end
    end
  end

  def runall(u, n, graph, topo, visited) when u > n do {true, topo} end
  def runall(u, n, graph, topo, visited) do
    {ret, topo, _, visited, time} = visit(u, graph, topo, MapSet.new(), visited)
    if not ret do
      {false, []}
    else
      runall(u + 1, n, graph, topo, visited)
    end
  end
end

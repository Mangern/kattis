defmodule Main do
  def start do
    [n, q] = 
      IO.gets("")
      |> String.split()
      |> Enum.map(&String.to_integer/1)

    books = case n do
      0 -> []
      _ -> Enum.map(1..n, fn i ->
        inp = IO.gets("")
        |> String.trim()
        [book, author] = String.split(inp, ", ")
        {author, book}
      end)
    end

    book_map = Enum.sort(books)
      |> Enum.with_index(1)
      |> Enum.reduce(%{}, fn {{auth, book}, idx}, mp ->
        Map.put(mp, book, idx)
      end)
    handle_queries(book_map, q)
  end

  def handle_queries(book_map, q) when q == 0 do :ok end
  def handle_queries(book_map, q) do
      inp = IO.gets("")
      |> String.trim()

      ret = Map.get(book_map, inp, -1)
      IO.puts("#{ret}")
      handle_queries(book_map, q - 1)
  end
end

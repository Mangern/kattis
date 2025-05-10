const std = @import("std");

fn gcd(a: u64, b: u64) u64 {
    if (b == 0) {
        return a;
    }
    return gcd(b, @mod(a, b));
}

pub fn main() !void {
    const stdout = std.io.getStdOut().writer();
    const stdin = std.io.getStdIn().reader();

    var arena = std.heap.ArenaAllocator.init(std.heap.page_allocator);
    defer arena.deinit();
    const allocator = arena.allocator();

    var buf: [100]u8 = undefined;
    var line: []u8 = undefined;

    var xs: [1005]i64 = undefined;
    var ys: [1005]i64 = undefined;

    const Line = struct { a: i64, b: i64, c: i64 };

    while (true) {
        line = (try stdin.readUntilDelimiterOrEof(&buf, '\n')).?;
        const N = try std.fmt.parseInt(usize, line, 10);

        if (N == 0) {
            break;
        }

        for (0..N) |i| {
            line = (try stdin.readUntilDelimiterOrEof(&buf, '\n')).?;
            var tokens = std.mem.tokenizeAny(u8, line, " ");
            const x = try std.fmt.parseInt(i64, tokens.next().?, 10);
            const y = try std.fmt.parseInt(i64, tokens.next().?, 10);
            xs[i] = x;
            ys[i] = y;
        }

        if (N == 1) {
            try stdout.print("1\n", .{});
            continue;
        }

        var line_count = std.AutoHashMap(Line, usize).init(allocator);
        defer line_count.deinit();
        for (0..N) |i| {
            var cur_lines = std.AutoHashMap(Line, usize).init(allocator);
            defer cur_lines.deinit();
            for (0..N) |j| {
                if (i == j) {
                    continue;
                }
                var a = ys[j] - ys[i];
                var b = xs[i] - xs[j];
                var c = xs[j] * ys[i] - xs[i] * ys[j];
                if (a < 0) {
                    a *= -1;
                    b *= -1;
                    c *= -1;
                }
                const g: i64 = @intCast(gcd(@abs(a), gcd(@abs(b), @abs(c))));
                a = @divTrunc(a, g);
                b = @divTrunc(b, g);
                c = @divTrunc(c, g);
                try cur_lines.put(.{ .a = a, .b = b, .c = c }, 1);
            }

            var it = cur_lines.iterator();

            while (it.next()) |entry| {
                const ky: Line = entry.key_ptr.*;
                const cnt = line_count.get(ky) orelse 0;
                try line_count.put(entry.key_ptr.*, cnt + 1);
            }
        }

        var it = line_count.iterator();
        var ans: usize = 0;
        while (it.next()) |entry| {
            ans = @max(ans, entry.value_ptr.*);
        }
        try stdout.print("{d}\n", .{ans});
    }
}

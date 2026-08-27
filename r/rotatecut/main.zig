const std = @import("std");

pub fn main() !void {
    const stdout = std.io.getStdOut().writer();
    const stdin = std.io.getStdIn().reader();
    var buf: [3000]u8 = undefined;

    var line = try stdin.readUntilDelimiterOrEof(&buf, '\n');

    var tokens = std.mem.tokenizeAny(u8, line.?, " \t\n");

    const T = try std.fmt.parseInt(usize, tokens.next().?, 10);

    for (0..T) |_| {
        line = try stdin.readUntilDelimiterOrEof(&buf, '\n');
        tokens = std.mem.tokenizeAny(u8, line.?, " \t\n");

        const N = try std.fmt.parseInt(usize, tokens.next().?, 10);
        const str = tokens.next().?;
        var l: usize = 0;
        var r: usize = str.len - 1;

        var flag: bool = true;

        for (0..N) |_| {
            const len = r - l + 1;
            if (len / 4 == 0) {
                break;
            }
            if (flag) {
                l += len / 4;
            } else {
                r -= len / 4;
            }
            flag = !flag;
        }
        try stdout.print("{s}\n", .{str[l .. r + 1]});
    }
}

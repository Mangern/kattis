const std = @import("std");

const UnionFind = struct {
    n: usize,
    p: []usize,
    val: []i64,
    allocator: std.mem.Allocator,

    pub fn init(allocator: std.mem.Allocator, n: usize) !UnionFind {
        const val = try allocator.alloc(i64, n);
        @memset(val, 0);
        const p = try allocator.alloc(usize, n);
        for (0..n) |i| {
            p[i] = i;
        }
        return UnionFind{ .n = n, .p = p, .val = val, .allocator = allocator };
    }

    pub fn deinit(self: UnionFind) void {
        self.allocator.free(self.p);
        self.allocator.free(self.val);
    }

    pub fn set_val(self: UnionFind, i: usize, v: i64) void {
        self.val[i] = v;
    }

    pub fn find(self: UnionFind, i: usize) usize {
        if (i == self.p[i]) {
            return i;
        }
        self.p[i] = self.find(self.p[i]);
        return self.p[i];
    }

    pub fn join(self: UnionFind, i: usize, j: usize) void {
        const ip = self.find(i);
        const jp = self.find(j);
        if (ip == jp) return;

        self.set_val(jp, self.val[jp] + self.val[ip]);
        self.p[ip] = jp;
    }
};

pub fn main() !void {
    const stdout = std.io.getStdOut().writer();
    const stdin = std.io.getStdIn().reader();
    const allocator = std.heap.page_allocator;
    var buffer: [100]u8 = undefined;

    var line = try stdin.readUntilDelimiterOrEof(&buffer, '\n');

    var tokens = std.mem.tokenizeAny(u8, line.?, " \t\n");

    const n = try std.fmt.parseInt(usize, tokens.next().?, 10);
    const m = try std.fmt.parseInt(usize, tokens.next().?, 10);

    const uf = try UnionFind.init(allocator, n);
    defer uf.deinit();

    for (0..n) |i| {
        line = try stdin.readUntilDelimiterOrEof(&buffer, '\n');
        uf.set_val(i, try std.fmt.parseInt(i64, line.?, 10));
    }

    for (0..m) |_| {
        line = try stdin.readUntilDelimiterOrEof(&buffer, '\n');
        tokens = std.mem.tokenizeAny(u8, line.?, " \t\n");
        const u = try std.fmt.parseInt(usize, tokens.next().?, 10);
        const v = try std.fmt.parseInt(usize, tokens.next().?, 10);
        uf.join(u, v);
    }

    for (0..n) |i| {
        const p = uf.find(i);
        if (uf.val[p] != 0) {
            try stdout.print("IMPOSSIBLE\n", .{});
            return;
        }
    }
    try stdout.print("POSSIBLE\n", .{});
}

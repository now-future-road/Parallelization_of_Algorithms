

import sympy as sp

x, y, z = sp.symbols('x y z')

f_gen = sp.Function('f')(x, y, z)
P = sp.Function('P')(x, y, z)
Q = sp.Function('Q')(x, y, z)
R = sp.Function('R')(x, y, z)
F_gen = sp.Matrix([P, Q, R])

def grad(f):
    return sp.Matrix([sp.diff(f, x), sp.diff(f, y), sp.diff(f, z)])

def div(F):
    return sp.diff(F[0], x) + sp.diff(F[1], y) + sp.diff(F[2], z)

def curl(F):
    return sp.Matrix([
        sp.diff(F[2], y) - sp.diff(F[1], z),
        sp.diff(F[0], z) - sp.diff(F[2], x),
        sp.diff(F[1], x) - sp.diff(F[0], y)
    ])

def lap(f):
    return sp.diff(f, x, 2) + sp.diff(f, y, 2) + sp.diff(f, z, 2)

print("=" * 60)
print("PROBLEM 6.1")
print("=" * 60)

f_61 = x**2 * y * z + sp.sin(y * z)
F_61 = sp.Matrix([x * y**2, z * sp.exp(x), x * y * z])

diff_61a_1 = sp.simplify(curl(grad(f_61)) - sp.Matrix([0, 0, 0]))
diff_61a_2 = sp.simplify(div(curl(F_61)) - 0)

print("6.1(a) curl(grad f) - 0 =")
sp.pprint(diff_61a_1)
print("6.1(a) div(curl F) - 0 =")
sp.pprint(diff_61a_2)

diff_61b_1 = sp.simplify(curl(grad(f_gen)) - sp.Matrix([0, 0, 0]))
diff_61b_2 = sp.simplify(div(curl(F_gen)) - 0)

print("\n6.1(b) General curl(grad f) - 0 =")
sp.pprint(diff_61b_1)
print("6.1(b) General div(curl F) - 0 =")
sp.pprint(diff_61b_2)

print("\n" + "=" * 60)
print("PROBLEM 6.2")
print("=" * 60)

f_62 = x**2 + y * z
F_62 = sp.Matrix([x * y, y * z, z * x])

lhs_62a = div(f_62 * F_62)
rhs_62a = f_62 * div(F_62) + F_62.dot(grad(f_62))
diff_62a = sp.simplify(lhs_62a - rhs_62a)

print("6.2(a) Concrete Difference (LHS - RHS) =")
sp.pprint(diff_62a)

lhs_62b = div(f_gen * F_gen)
rhs_62b = f_gen * div(F_gen) + F_gen.dot(grad(f_gen))
diff_62b = sp.simplify(lhs_62b - rhs_62b)

print("6.2(b) General Difference (LHS - RHS) =")
sp.pprint(diff_62b)

print("\n" + "=" * 60)
print("PROBLEM 6.3")
print("=" * 60)

f_63 = sp.exp(x * y)
F_63 = sp.Matrix([z, x**2, y * sp.sin(z)])

lhs_63a = curl(f_63 * F_63)
rhs_63a = grad(f_63).cross(F_63) + f_63 * curl(F_63)
diff_63a = sp.simplify(lhs_63a - rhs_63a)

print("6.3(a) Concrete Difference (LHS - RHS) =")
sp.pprint(diff_63a)

lhs_63b = curl(f_63 * F_gen)
lhs_63_gen = curl(f_gen * F_gen)
rhs_63_gen = grad(f_gen).cross(F_gen) + f_gen * curl(F_gen)
diff_63b = sp.simplify(lhs_63_gen - rhs_63_gen)

print("6.3(b) General Difference (LHS - RHS) =")
sp.pprint(diff_63b)

print("\n" + "=" * 60)
print("PROBLEM 6.4")
print("=" * 60)

U = sp.Function('U')(x, y, z)
V = sp.Function('V')(x, y, z)
W = sp.Function('W')(x, y, z)
G_gen = sp.Matrix([U, V, W])

lhs_64 = div(F_gen.cross(G_gen))
rhs_64 = G_gen.dot(curl(F_gen)) - F_gen.dot(curl(G_gen))
diff_64 = sp.simplify(lhs_64 - rhs_64)

print("6.4 General Difference div(F x G) - (G . curl F - F . curl G) =")
sp.pprint(diff_64)

print("\n" + "=" * 60)
print("PROBLEM 6.5")
print("=" * 60)

lhs_65a = div(grad(f_gen))
rhs_65a = lap(f_gen)
diff_65a = sp.simplify(lhs_65a - rhs_65a)

print("6.5(a) General Difference div(grad f) - lap(f) =")
sp.pprint(diff_65a)

lap_F_gen = sp.Matrix([lap(P), lap(Q), lap(R)])

lhs_65b = curl(curl(F_gen))
rhs_65b = grad(div(F_gen)) - lap_F_gen
diff_65b = sp.simplify(lhs_65b - rhs_65b)

print("6.5(b) General Difference curl(curl F) - (grad(div F) - lap(F)) =")
sp.pprint(diff_65b)
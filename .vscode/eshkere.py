def f(x):
    return x ** 2


def different(x, delta, f):
    return (f(x + delta) - f(x)) / delta


def different_central(x, delta, f):
    return (f(x + delta) - f(x - delta)) / (2 * delta)


x = float(input("x = "))
exact = 2 * x          

print(f"\nТочная производная f'({x}) = {exact}\n")
print(f"{'delta':<10} {'Конечная':<20} {'Ошибка 1':<20} {'Центральная':<20} {'Ошибка 2':<20}")
print("-" * 90)

for delta in (0.1, 0.01, 0.001, 0.0001):
    d1 = different(x, delta, f)
    d2 = different_central(x, delta, f)
    print(f"{delta:<10} {d1:<20.10f} {abs(d1-exact):<20.10f} "
          f"{d2:<20.10f} {abs(d2-exact):<20.10f}")
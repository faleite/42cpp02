# Knowledge

## Floating point number representation

```bash
seeeeeeeemmmmmmmmmmmmmmmmmmmmmmm    meaning
31                             0    bit #

s = sign bit, e = exponent, m = mantissa
```

Property | Value for float |	Value for double
---------|-----------------|--------------------
Largest representable number	         | 3.402823466e+38	| 1.7976931348623157e+308
Smallest number without losing precision | 1.175494351e-38	| 2.2250738585072014e-308
Smallest representable number(*)	     | 1.401298464e-45	| 5e-324
Mantissa bits	                         | 23               | 52
Exponent bits	                         | 8	            | 11
Epsilon(**)	                             | 1.1929093e-7	    | 2.220446049250313e-16

## Overload of the insertion («) operator
```cpp
std::ostream &operator<<(std::ostream &o, const Fixed &i);
```
### Sobre
A linha de código `std::ostream & operator<<(std::ostream & o, Sample const & i);` declara uma sobrecarga do operador de inserção (`<<`) para uma classe `Sample`. Isso permite que objetos da classe `Sample` possam ser inseridos em fluxos de saída, como `std::cout` ou `std::ofstream`.

### Conceitos e Explicação

Vamos decompor e explicar cada parte dessa declaração:

1. **Sobrecarga de Operador**:
   - Em C++, os operadores podem ser sobrecarregados para fornecer comportamento específico quando usados com objetos de uma classe definida pelo usuário.
   - `operator<<` é o operador de inserção, usado para enviar dados para um fluxo de saída.

2. **Retorno `std::ostream &`**:
   - A função retorna uma referência a um objeto `std::ostream`. Isso permite a chamada encadeada (chaining) do operador de inserção.
   - Por exemplo: `std::cout << obj1 << obj2;` é possível devido a essa referência retornada.

3. **Parâmetros `std::ostream & o, Sample const & i`**:
   - `std::ostream & o`: Referência ao fluxo de saída onde os dados serão enviados (como `std::cout` ou `std::ofstream`).
   - `Sample const & i`: Referência constante a um objeto da classe `Sample` que será inserido no fluxo.


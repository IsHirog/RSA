# Implementação do Algoritmo RSA em C com GMP

Este projeto implementa o algoritmo RSA em C utilizando a biblioteca GMP (GNU Multiple Precision Arithmetic Library) para realizar operações matemáticas com números grandes.

## Funcionalidades
- Geração de chaves RSA.
- Criptografia de mensagens usando a chave pública.
- Descriptografia de mensagens usando a chave privada.

## Requisitos

Antes de compilar e executar o código, certifique-se de ter a biblioteca GMP instalada no seu sistema. Em distribuições Linux baseadas em Debian, você pode instalar a GMP com:

```bash
sudo apt-get install libgmp-dev
```
## Como instalar a GMP no Windows

### Método 1: Usando MSYS2 (Recomendado)
1. **Baixe o MSYS2:**  
   - Acesse: [https://www.msys2.org/](https://www.msys2.org/)  
   - Instale o MSYS2 e abra **MSYS2 MinGW 64-bit**.

2. **Atualize os pacotes:**
   ```sh
   pacman -Syu
   ```

3. **Instale a GMP:**
   ```sh
   pacman -S mingw-w64-x86_64-gmp
   ```

4. **Configure o compilador (se necessário):**
   - Verifique o caminho do compilador (`gcc` ou `clang`).
   - Adicione o diretório `mingw64/bin` ao `PATH`.


## 🔧 Compilação e Execução

Para compilar os arquivos, utilize o `gcc` com a biblioteca GMP:

```bash
gcc -o criptografar criptografar.c -lgmp
```
```bash
gcc -o gerarChaves gerarChaves.c -lgmp
```
```bash
gcc -o descriptografar descriptografar.c -lgmp
```

Para executar o programa:

```bash
./nomeDoArquivo
```

## 📜 Descrição do Código

O código está dividido em três partes principais:

### 1️⃣ Geração de Chaves
- O usuário insere dois números primos `p` e `q`.
- Calcula-se `n = p * q`.
- Calcula-se o totiente `ϕ(n) = (p-1) * (q-1)`.
- Escolhe-se um valor de `e` que seja coprimo a `ϕ(n)`.
- Calcula-se `d`, o inverso multiplicativo de `e` módulo `ϕ(n)`.
- A chave pública é `(n, e)` e a chave privada é `(d, ϕ(n))`.

### 2️⃣ Criptografia
- O usuário insere a mensagem a ser criptografada.
- Cada caractere da mensagem é convertido para um número inteiro e elevado a `e`, módulo `n`.
- O resultado é armazenado como a mensagem criptografada.

### 3️⃣ Descriptografia
- O usuário insere os números criptografados.
- Cada número é elevado a `d`, módulo `n`, para recuperar os caracteres originais.
- A mensagem original é reconstruída e exibida.

## 📌 Exemplo de Uso

**Entrada:**
```
Digite o p: 61
Digite o q: 53
Digite o e: 17
Digite a mensagem: Hello
```

**Saída:**
```
Mensagem criptografada: 2790 3129 881 881 1611
Mensagem descriptografada: Hello
```


## 📜 Licença
Este projeto é de código aberto e pode ser utilizado para fins educacionais e acadêmicos.

---

Caso tenha dúvidas ou sugestões, sinta-se à vontade para contribuir!

# ⏰ Sincronização Automática de Hora no Windows

Este projeto oferece duas formas de manter o horário do sistema sincronizado no Windows:

- Um **script em Batch (`.bat`)** com agendamento automático via `Task Scheduler`.
- Um **executável em C (`.exe`)**, que realiza a sincronização de forma invisível, sem abrir janelas.

---

## 📦 Conteúdo

- [`setup_sync_time.bat`](setup_sync_time.bat) – Script que automatiza a criação da tarefa agendada.
- [`sync_clock.c`](sync_clock.c) – Código-fonte em C para sincronização invisível.
- [`sync_clock.exe`](sync_clock.exe) – Executável gerado a partir do código C (não exibe console ou janelas).

---

## ✅ Funcionalidades

- Sincroniza a hora do sistema com o servidor NTP `a.st1.ntp.br`.
- Executa de forma silenciosa, com privilégios de administrador.
- O script `.bat` pode agendar sincronizações de hora em hora.
- O executável `.exe` funciona como alternativa leve ao script agendado.

---

## 📥 Download e Uso

### Usando o Script Batch

1. **Baixe o arquivo** [`setup_sync_time.bat`](setup_sync_time.bat) ou clone este repositório:
   ```sh
   git clone https://github.com/lgfranco22/sync_time.git
   ```
2. **Execute o script**:
   - Dê um duplo clique em `setup_sync_time.bat`.
   - O script solicitará elevação automática de privilégios se necessário.
   - Uma MessageBox será exibida indicando o sucesso ou falha da configuração.

---

### Usando o Executável em C

1. **Baixe ou compile** o executável `sync_clock.exe`.
2. **Execute como Administrador**:
   - O próprio executável verifica se há privilégios administrativos.
   - Se necessário, ele solicitará elevação automaticamente via UAC.
   - Todo o processo é realizado em segundo plano, sem janelas visíveis.

---

## ⚙️ Como Compilar o Código C

Você pode compilar o arquivo `sync_clock.c` usando o [MinGW](https://www.mingw-w64.org/) com o seguinte comando:

```bash
gcc -o sync_clock.exe sync_clock.c -mwindows -lShell32 -ladvapi32
```

### Detalhes:
- `-mwindows`: impede que uma janela de console apareça.
- `-lShell32`: necessário para `ShellExecuteEx` (elevação).
- `-ladvapi32`: necessário para `CheckTokenMembership` (verificação de administrador).

Certifique-se de estar no mesmo diretório do `sync_clock.c` ao compilar.

---

## 🔍 Comandos Úteis

### Verificar se a tarefa agendada foi criada corretamente:
```cmd
schtasks /query /tn "SincronizarHora"
```

### Remover a tarefa (caso deseje desfazer):
```cmd
schtasks /delete /tn "SincronizarHora" /f
```

---

## ⚠️ Observações

- **Auto Elevação de Privilégios:**  
  Tanto o script quanto o executável verificam e solicitam elevação automaticamente se necessário.

- **Servidor NTP:**  
  A sincronização é feita com o servidor confiável brasileiro `a.st1.ntp.br`.

- **Compatibilidade:**  
  Testado e compatível com **Windows 10** e **Windows 11**.

---

## 📜 Licença

Este projeto é de código aberto e está disponível sob a licença MIT.

---

🚀 **Mantenha o horário do seu Windows sempre correto — automática e silenciosamente!**

---

# ⏰ Sincronização Automática de Hora no Windows

Este projeto contém um **script em Batch** que automatiza a sincronização do relógio do sistema no Windows. Com ele, você pode:

- Sincronizar a hora do sistema de forma automática.
- Agendar a execução do script **de hora em hora** com privilégios elevados.
- Receber uma **MessageBox** com o status da criação da tarefa.
- Executar a sincronização imediatamente após a configuração.

## 📥 Download e Uso

1. **Baixe o arquivo** [`setup_sync_time.bat`](setup_sync_time.bat) ou clone este repositório:
   ```sh
   git clone https://github.com/seu-usuario/seu-repositorio.git
   ```
2. **Execute o script**:
   - Basta dar um duplo clique em `setup_sync_time.bat`.
   - Caso não possua privilégios, o script se auto eleva automaticamente.
   - Uma MessageBox será exibida para confirmar se a tarefa foi criada corretamente.

## 🛠 Como Funciona

### 1️⃣ Criação da Pasta e do Script de Sincronização
O script cria a pasta `C:\Scripts` e gera o arquivo `sync_time.bat`, que contém os comandos necessários para sincronizar a hora do sistema utilizando o `w32tm`.

### 2️⃣ Agendamento da Tarefa
Utilizando o comando `schtasks`, o script agenda a execução do `sync_time.bat` **de hora em hora**, garantindo que o relógio do sistema seja atualizado com frequência.

### 3️⃣ Verificação e Notificação
Após agendar a tarefa, o script realiza uma verificação e exibe uma MessageBox para informar:
- ✅ **Sucesso** → "A tarefa foi criada com sucesso!"
- ❌ **Erro** → "Erro ao criar a tarefa! Verifique as permissões."

### 4️⃣ Execução Imediata
Após a configuração, o script executa a sincronização imediatamente, garantindo que o relógio do sistema esteja correto sem esperar a próxima execução agendada.

## 🔍 Comandos Úteis

### Verificar se a tarefa foi criada corretamente:
```cmd
schtasks /query /tn "SincronizarHora"
```

### Remover a tarefa (caso precise refazer):
```cmd
schtasks /delete /tn "SincronizarHora" /f
```

## ⚠️ Observações

- **Auto Elevação de Privilégios:**  
  O script se auto eleva, portanto, não é necessário executá-lo manualmente como Administrador.
  
- **Servidor NTP:**  
  A sincronização utiliza o servidor `a.st1.ntp.br`.
  
- **Compatibilidade:**  
  Compatível com **Windows 10 e 11**.

## 📜 Licença

Este projeto é de código aberto e está disponível sob a licença MIT.

---

🚀 **Mantenha o horário do seu Windows sempre correto de forma automática!**

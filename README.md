# ⏰ Sincronizar Hora do Windows Automaticamente

Este projeto contém um **script em Batch** que:
✅ Cria um script para sincronizar a hora do sistema.
✅ Agenda a execução automática **de hora em hora** com permissões de administrador.
✅ Exibe uma **MessageBox** informando o status da criação da tarefa.
✅ Executa a sincronização imediatamente após a configuração.

## 📥 Download e Uso
1. **Baixe o arquivo** [`setup_sync_time.bat`](setup_sync_time.bat) ou clone este repositório:
   ```sh
   git clone https://github.com/seu-usuario/seu-repositorio.git
   ```
2. **Execute o script como Administrador**:
   - Clique com o botão direito em `setup_sync_time.bat` e selecione **Executar como Administrador**.
   - Uma MessageBox confirmará se a tarefa foi criada corretamente.

## 🛠 Como Funciona
### 1️⃣ Criando a Pasta e o Script de Sincronização
O script cria a pasta `C:\Scripts` e o arquivo `sync_time.bat` com os comandos para sincronizar a hora do sistema usando `w32tm`.

### 2️⃣ Agendando a Tarefa
O script usa `schtasks` para agendar a execução do script **de hora em hora** com privilégios elevados.

### 3️⃣ Verificação e Notificação
Após agendar a tarefa, o script verifica se a criação foi bem-sucedida e exibe uma MessageBox:
- ✅ **Sucesso** → "A tarefa foi criada com sucesso!"
- ❌ **Erro** → "Erro ao criar a tarefa! Verifique as permissões."

### 4️⃣ Execução Imediata
Após criar a tarefa, o script executa a sincronização imediatamente.

## 🔍 Comandos Úteis
### ✅ Verificar se a tarefa foi criada corretamente:
```cmd
schtasks /query /tn "SincronizarHora"
```

### ❌ Remover a tarefa (caso precise refazer):
```cmd
schtasks /delete /tn "SincronizarHora" /f
```

## ⚠️ Observações
- O script **precisa ser executado como Administrador** para funcionar corretamente.
- A sincronização usa o servidor `a.st1.ntp.br`.
- Compatível com **Windows 10 e 11**.

## 📜 Licença
Este projeto é de código aberto e está disponível sob a licença MIT.

---

🚀 **Mantenha seu Windows sempre com a hora correta automaticamente!**


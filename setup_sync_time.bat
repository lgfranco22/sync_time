@echo off
echo ==========================================
echo Criando a pasta C:\Scripts...
echo ==========================================
mkdir "C:\Scripts" 2>nul

echo ==========================================
echo Criando o script sync_time.bat...
echo ==========================================
(
echo @echo off
echo echo Sincronizando hora do sistema...
echo net stop w32time
echo w32tm /config /manualpeerlist:"a.st1.ntp.br" /syncfromflags:manual /reliable:YES /update
echo net start w32time
echo w32tm /resync
echo echo Sincronizacao concluida!
) > "C:\Scripts\sync_time.bat"

echo ==========================================
echo Criando a tarefa agendada...
echo ==========================================
schtasks /create /tn "SincronizarHora" /tr "cmd.exe /c start /b /min C:\Scripts\sync_time.bat" /sc HOURLY /RL HIGHEST /F >nul 2>&1

:: Verificar se a tarefa foi criada corretamente
schtasks /query /tn "SincronizarHora" >nul 2>&1
if %errorlevel% equ 0 (
    echo ==========================================
    echo Tarefa criada com sucesso!
    echo ==========================================
    powershell -Command "[System.Windows.MessageBox]::Show('A tarefa foi criada com sucesso!', 'Sucesso', 0, 64)"
) else (
    echo ==========================================
    echo Erro ao criar a tarefa!
    echo ==========================================
    powershell -Command "[System.Windows.MessageBox]::Show('Erro ao criar a tarefa! Verifique as permissões.', 'Erro', 0, 16)"
    exit /b 1
)

echo ==========================================
echo Executando a sincronizacao agora...
echo ==========================================
schtasks /run /tn "SincronizarHora"

echo ==========================================
echo Processo concluido!
echo ==========================================
pause

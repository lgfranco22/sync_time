#include <windows.h>
#include <shellapi.h>
#include <stdio.h>

BOOL IsRunAsAdmin() {
    BOOL isAdmin = FALSE;
    PSID adminGroup = NULL;
    SID_IDENTIFIER_AUTHORITY ntAuthority = SECURITY_NT_AUTHORITY;

    if (AllocateAndInitializeSid(&ntAuthority, 2,
                                 SECURITY_BUILTIN_DOMAIN_RID,
                                 DOMAIN_ALIAS_RID_ADMINS,
                                 0, 0, 0, 0, 0, 0,
                                 &adminGroup)) {
        CheckTokenMembership(NULL, adminGroup, &isAdmin);
        FreeSid(adminGroup);
    }

    return isAdmin;
}

int RunHiddenCommand(const char *cmd) {
    STARTUPINFOA si = {0};
    PROCESS_INFORMATION pi = {0};

    si.cb = sizeof(si);
    si.dwFlags = STARTF_USESHOWWINDOW;
    si.wShowWindow = SW_HIDE;

    // Criar uma string mutável para CreateProcess
    char command[512];
    snprintf(command, sizeof(command), "cmd.exe /c %s", cmd);

    if (!CreateProcessA(NULL, command, NULL, NULL, FALSE, CREATE_NO_WINDOW,
                        NULL, NULL, &si, &pi)) {
        return GetLastError();
    }

    // Esperar o processo terminar
    WaitForSingleObject(pi.hProcess, INFINITE);
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
    return 0;
}

int main() {
    if (!IsRunAsAdmin()) {
        // Relançar com privilégios de administrador
        SHELLEXECUTEINFOA sei = {0};
        sei.cbSize = sizeof(sei);
        sei.fMask = SEE_MASK_NOCLOSEPROCESS;
        sei.lpVerb = "runas";
        sei.lpFile = GetCommandLineA();
        sei.nShow = SW_HIDE;

        if (!ShellExecuteExA(&sei)) {
            MessageBoxA(NULL, "Falha ao elevar privilégios.", "Erro", MB_OK | MB_ICONERROR);
            return 1;
        }

        return 0;
    }

    // Comandos para sincronizar o horário
    RunHiddenCommand("net stop w32time");
    RunHiddenCommand("w32tm /config /manualpeerlist:\"a.st1.ntp.br\" /syncfromflags:manual /reliable:YES /update");
    RunHiddenCommand("net start w32time");
    RunHiddenCommand("w32tm /resync");

    return 0;
}

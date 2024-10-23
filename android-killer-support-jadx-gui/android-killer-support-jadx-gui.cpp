// android-killer-support-jadx-gui.cpp : 定义应用程序的入口点。
//

#include "framework.h"
#include "android-killer-support-jadx-gui.h"

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    STARTUPINFO sInfo;
    PROCESS_INFORMATION pInfo;

    ZeroMemory(&sInfo, sizeof(sInfo));
    sInfo.cb = sizeof(sInfo);
    ZeroMemory(&pInfo, sizeof(pInfo));

    // 启动另一个程序
    if (CreateProcess(
        L".\\tools\\JadxGui\\jadx-gui.exe",     // 应用程序路径
        NULL,                                   // 命令行参数
        NULL,                                   // 进程句柄不继承
        NULL,                                   // 线程句柄不继承
        FALSE,                                  // 不继承句柄
        CREATE_NO_WINDOW,                       // 不显示窗口
        NULL,                                   // 使用父进程的环境
        NULL,                                   // 使用父进程的工作目录
        &sInfo,                                 // 启动信息
        &pInfo))                                // 进程信息
    {
        // 等待进程结束
        WaitForSingleObject(pInfo.hProcess, INFINITE);

        // 关闭句柄
        CloseHandle(pInfo.hProcess);
        CloseHandle(pInfo.hThread);

        return 0;
    }
    else {
        // 如果进程创建失败，输出错误码
        MessageBox(NULL, L"jadx-gui 启动失败！", L"Error", MB_OK);

        return -1;
    }
}


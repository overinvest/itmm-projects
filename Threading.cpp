Program 1:
#include <Windows.h>
#include <iostream>

int main() 
{
    STARTUPINFO si;
    PROCESS_INFORMATION pi;

    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));

    // Create the child process. 
    if (!CreateProcess(TEXT("C:\\Windows\\System32\\notepad.exe"),   // No module name (use command line)
        NULL,        // Command line
        NULL,           // Process handle not inheritable
        NULL,           // Thread handle not inheritable
        FALSE,          // Set handle inheritance to FALSE
        0,              // No creation flags
        NULL,           // Use parent's environment block
        NULL,           // Use parent's starting directory 
        &si,            // Pointer to STARTUPINFO structure
        &pi)           // Pointer to PROCESS_INFORMATION structure
    )
    {
        std::cout << "CreateProcess failed" << std::endl;
        return -1;
    }

    // Wait until child process exits.
    WaitForSingleObject(pi.hProcess, INFINITE);

    // Close process and thread handles. 
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);

    return 0;
}

// Program 2:
#include <thread>
#include <iostream>
#include <atomic>

std::atomic<int> Var(0);

void threadFunction(int value) 
{
    for (int i = 0; i < 100000000; ++i) {
        if (value == 1) {
            Var++;
        } else {
            Var--;
        }
    }
}

int main() 
{
    std::cout << "Var initial value: " << Var << std::endl;
    
    std::thread t1(threadFunction, 1);
    std::thread t2(threadFunction, 1);
    std::thread t3(threadFunction, 1);
    std::thread t4(threadFunction, 1);
    std::thread t5(threadFunction, 1);
    std::thread t6(threadFunction, 1);
    std::thread t7(threadFunction, 1);
    std::thread t8(threadFunction, 1);
    std::thread t9(threadFunction, 1);
    std::thread t10(threadFunction, 1);
    std::thread t11(threadFunction, -1);
    std::thread t12(threadFunction, -1);
    std::thread t13(threadFunction, -1);
    std::thread t14(threadFunction, -1);
    std::thread t15(threadFunction, -1);
    std::thread t16(threadFunction, -1);
    std::thread t17(threadFunction, -1);
    std::thread t18(threadFunction, -1);
    std::thread t19(threadFunction, -1);
    std::thread t20(threadFunction, -1);
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    t6.join();
    t7.join();
    t8.join();
    t9.join();
    t10.join();
    t11.join();
    t12.join();
    t13.join();
    t14.join();
    t15.join();
    t16.join();
    t17.join();
    t18.join();
    t19.join();
    t20.join();

    std::cout << "Var final value: " << Var << std::endl;

    return 0;
}
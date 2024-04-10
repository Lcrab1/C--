BOOL CIocpServer::ServerRun(USHORT ListenPort)
{

    BOOL IsOk = TRUE;          //绑定套接
    SOCKADDR_IN ServerAddress; //结构体

    //创建事件对象 最后一个参数表示事件的名称,传入NULL代表传入的是一个匿名对象
    // Kernel32.dll
    m_KillEventHandle = CreateEvent(NULL, FALSE, FALSE, NULL);

    if (m_KillEventHandle == NULL)
    {
        return FALSE;
    }

    //创建一个监听事件
    m_listenSocket = WSASocketW(AF_INET, SOCK_STREAM, 0, NULL, 0, WSA_FLAG_OVERLAPPED); //重叠 异步Io  CPU
    if (m_listenSocket == INVALID_SOCKET)
    {
        IsOk = FALSE;
        goto Error;
    }

    // WSA开头  创建一个网络的事件
    // Ws2_32.dll
    m_ListenEventHandle = WSACreateEvent(); // NULL true,false NULL
    // The WSACreateEvent function creates a manual-reset event object with an initial state of nonsignaled.
    //创建一个监听事件(网络代码)(Ws2_32.dll)

    if (m_ListenEventHandle == WSA_INVALID_EVENT)
    {
        IsOk = FALSE;
        goto Error;
    }

    //将监听套接字与事件进行关联并授予FD_ACCEPT与的FD_CLOSE属性
    BOOL ConnectOk = WSAEventSelect(m_listenSocket,
                                    m_ListenEventHandle,
                                    FD_ACCEPT | FD_CLOSE);
    /*FD_ACCEPT表示有新的连接请求，FD_CLOSE表示连接已经关闭。
    当这些事件中的任何一个发生时，m_ListenEventHandle事件对象就会被设置为信号状态。*/

    if (ConnectOk == SOCKET_ERROR)
    {
        IsOk = FALSE;
        goto Error;
    }

    //初始化Server端网卡

    //通信端口 0 - 2^16-1
    // Http:超文本传输协议  80

    ServerAddress.sin_port = htons(ListenPort); // host to net String ini 文件设置的监听端口撸进结构中
    ServerAddress.sin_family = AF_INET;
    ServerAddress.sin_addr.s_addr = INADDR_ANY;
    // ServerAddress.sin_addr.S_un.S_addr = INADDR_ANY;  //IP地址
    // INADDR_ANY是一个特殊的宏常量，表示绑定到所有可用的网络接口上。

    //绑定套接字
    //套接字与网卡关联

    //将服务器监听套接字与指定的 IP 地址和端口号绑定在一起
    BOOL bindOk = bind(m_listenSocket,
                       (sockaddr *)&ServerAddress,
                       sizeof(ServerAddress));

    if (bindOk == SOCKET_ERROR)
    {
        IsOk = FALSE;
        goto Error;
    }

    //保安上班监听
    //将服务器的监听套接字置为监听状态
    BOOL listenOk = listen(m_listenSocket, SOMAXCONN); //监听能力
    if (listenOk == SOCKET_ERROR)
    {
        IsOk = FALSE;
        goto Error;
    }

    //创建监听线程
    m_ListenThreadHandle =
        (HANDLE)CreateThread(NULL,
                             0,
                             (LPTHREAD_START_ROUTINE)ListenThreadProcedure,
                             (void *)this, //向Thread回调函数传入this 方便我们的线程回调访问类中的成员
                             0,
                             NULL);

    if (m_ListenThreadHandle == INVALID_HANDLE_VALUE)
    {
        IsOk = FALSE;
        goto Error;
    }

    IocpInit();
    return TRUE;

Error:

    if (IsOk == FALSE)
    {
        if (m_listenSocket != INVALID_SOCKET)
        {
            closesocket(m_listenSocket);
            m_listenSocket = INVALID_SOCKET;
        }
    }
    return 0;
}
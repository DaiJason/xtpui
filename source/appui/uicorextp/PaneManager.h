#pragma once

class CEmbedWnd;

//! ���������࣬ÿ���������һ�� IWndFactory �Ӵ���
/*!
    \ingroup _GROUP_APPUI_
*/
class CPaneManager
{
public:
    //! ���캯��
    /*!
        \param paneOwner ��崰�ڵ�ӵ����
        \param manager ͣ�����������
        \param folderName ��岼���ļ�����λ�ã����ļ�����
    */
    CPaneManager(CWnd* paneOwner, CXTPDockingPaneManager* manager, 
        const std::wstring& folderName = L"");

    //! ��������
    virtual ~CPaneManager();

public:
    //! ������ͼ��ID��������Ӵ��ڶ���, CEmbedWnd
    CWnd* FindPaneWnd(const char* clsidView, UINT* pID = NULL) const;

    //! ��ʾһ�����
    /*!
        \param id ��崰�ڵ�ID
        \param activate �Ƿ񽫸��������Ϊ��ǰ����
        \return �Ƿ�ִ�гɹ�
    */
    bool ShowPane(UINT id, bool activate);

    //! ����һ�����
    bool HidePane(UINT id);

    //! �л���ָ����ʶ���Ƶ���岼����
    bool SwitchPaneLayout(const std::wstring& name);

    //! ������崰�ڸ���
    long GetViewCount() const;

    //! ����ָ����ŵ�����Ӵ��ڶ���, CEmbedWnd
    CWnd* GetView(long index) const;

    //! ��������Ӵ����е���Ƕ IWndFactory ����
    AnyObject GetViewObject(CWnd* pWnd) const;

public:
    //! ������崰��
    bool CreateDockingPanes();

    //! ��Ӧ���֪ͨ��Ϣ
    bool OnDockingPaneNotify(WPARAM wParam, LPARAM lParam);

    //! ������岼��λ��
    void SaveDockingPanes();

    //! ����������崰��
    void DestroyPanes();

    //! ����������Ϣ������Ӵ���
    BOOL DoCmdMsg(UINT id, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pInfo);

private:
    void CreatePanes(const std::wstring& filename);
    void ResetPaneOptions(const std::wstring& filename);
    void LoadPaneLayout(const std::wstring& filename);
    std::wstring MakeFileName(const std::wstring& shortName) const;
    bool IsSameTimeStamp(const std::wstring& userFile, const std::wstring& initialFile);
    bool SaveTimeStamp(const std::wstring& userFile, const std::wstring& initialFile);

private:
    std::map<UINT, CEmbedWnd*>  m_mapView;
    bool                    m_designMode;
    std::wstring            m_folderName;
    CWnd*                   m_paneOwner;
    CXTPDockingPaneManager* m_manager;
};

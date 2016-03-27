

#ifndef UPDATE_CHECKER_H
#define UPDATE_CHECKER_H

#include <QtGlobal>
#include <QObject>
#include "tcommon.h"

#include <QNetworkAccessManager>
#include <QUrl>
#include <QString>
#include <QDate>

#undef DVAPI
#undef DVVAR
#ifdef TOONZQT_EXPORTS
#define DVAPI DV_EXPORT_API
#define DVVAR DV_EXPORT_VAR
#else
#define DVAPI DV_IMPORT_API
#define DVVAR DV_IMPORT_VAR
#endif

class DVAPI UpdateChecker
	: public QObject
{
	Q_OBJECT
	bool m_httpRequestAborted;
	int m_httpGetId;

	QDate m_updateDate;
	QUrl m_webPageUrl;

public:
	UpdateChecker(const QString &requestToServer);

	QDate getUpdateDate() const { return m_updateDate; }
	QUrl getWebPageUrl() const { return m_webPageUrl; }

protected slots:
	void httpRequestStarted(int requestId) {}
	void httpRequestFinished(QNetworkReply *);
	void slotAuthenticationRequired(const QString &hostName, quint16, QAuthenticator *authenticator);
	void httpStateChanged(int state);
};

#endif // UPDATE_CHECKER_H

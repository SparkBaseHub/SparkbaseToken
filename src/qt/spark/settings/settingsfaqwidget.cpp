// Copyright (c) 2019 The PIVX developers
// Copyright (c) 2017-2021 Sparkbase AG
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#if defined(HAVE_CONFIG_H)
#include "config/spark-config.h"
#endif

#include "qt/spark/settings/settingsfaqwidget.h"
#include "qt/spark/settings/forms/ui_settingsfaqwidget.h"
#include "clientmodel.h"
#include "qt/spark/qtutils.h"

#include <QScrollBar>
#include <QMetaObject>

SettingsFaqWidget::SettingsFaqWidget(SPARKGUI* parent, ClientModel* _model) :
    QDialog(parent),
    ui(new Ui::SettingsFaqWidget),
    clientModel(_model)
{
    ui->setupUi(this);
    this->setStyleSheet(parent->styleSheet());

#ifdef Q_OS_MAC
    ui->container->load("://bg-welcome");
    setCssProperty(ui->container, "container-welcome-no-image");
#else
    setCssProperty(ui->container, "container-welcome");
#endif
    setCssProperty(ui->labelTitle, "text-title-faq");
    setCssProperty(ui->labelWebLink, "text-content-white");

    // Content
    setCssProperty({
           ui->labelNumber_Intro,
           ui->labelNumber_UnspendableSPARKS,
           ui->labelNumber_Stake,
           ui->labelNumber_Support,
           ui->labelNumber_Masternode,
           ui->labelNumber_MNController
        }, "container-number-faq");

    setCssProperty({
              ui->labelSubtitle_Intro,
              ui->labelSubtitle_UnspendableSPARKS,
              ui->labelSubtitle_Stake,
              ui->labelSubtitle_Support,
              ui->labelSubtitle_Masternode,
              ui->labelSubtitle_MNController
            }, "text-subtitle-faq");


    setCssProperty({
              ui->labelContent_Intro,
              ui->labelContent_UnspendableSPARKS,
              ui->labelContent_Stake,
              ui->labelContent_Support,
              ui->labelContent_Masternode,
              ui->labelContent_MNController
            }, "text-content-faq");


    setCssProperty({
              ui->pushButton_Intro,
              ui->pushButton_UnspendableSPARKS,
              ui->pushButton_Stake,
              ui->pushButton_Support,
              ui->pushButton_Masternode,
              ui->pushButton_MNController
            }, "btn-faq-options");

    ui->labelContent_Support->setOpenExternalLinks(true);
    ui->labelContent_MNController->setOpenExternalLinks(true);
    //ui->pushButtonWebLink->setOpenExternalLinks(true);

    // Set FAQ content strings
/*
    QString introContent = formatFAQContent(
        formatFAQParagraph(
            tr("Sparkbase Token is a form of utility token using blockchain technology that can be easily transferred globally, instantly, and with near zero fees. Sparkbase incorporates market leading security & privacy and is also the first PoS (Proof of Stake) Cryptocurrency to implement Sapling(SHIELD), a zk-SNARKs based privacy protocol.")) +
        formatFAQParagraph(
            tr("Sparkbase Token utilizes a Proof of Stake (PoS) consensus system algorithm, allowing all owners of Sparkbase to participate in earning block rewards while securing the network with full node wallets, as well as to run Masternodes to create and vote on proposals.")));
*/
    QString introContent = tr("introContent");
    ui->labelContent_Intro->setText(introContent);
/*
    QString unspendableSPARKSContent = formatFAQContent(
        formatFAQParagraph(
            tr("Newly received SPARKS requires 6 confirmations on the network to become eligible for spending which can take ~6 minutes.")) +
        formatFAQParagraph(
            tr("Your Sparkbase Token wallet also needs to be completely synchronized "
               "to see and spend balances on the network.")));
*/
    QString unspendableSPARKSContent =  tr("unspendableSPARKSContent");
    ui->labelContent_UnspendableSPARKS->setText(unspendableSPARKSContent);
/*
    QString stakeContent = formatFAQContent(
        formatFAQOrderedList(
            formatFAQListItem(tr("Make sure your wallet is completely synchronized and you are using the latest release.")) +
            formatFAQListItem(tr("You must have a balance of SPARKS with a minimum of 600 confirmations.")) +
            formatFAQListItem(tr("Your wallet must stay online and be unlocked for staking purposes.")) +
            formatFAQListItem(tr("Once all those steps are followed staking should be enabled."))) +
        formatFAQParagraph(
            tr("You can see the status of staking in the wallet by mousing over the package icon in the row on the top left of the wallet interface. The package will be lit up and will state \"Staking Enabled\" to indicate it is staking. Using the command line interface (%1); the command %2 will confirm that staking is active.")
                .arg("spark-cli", "<span style=\"font-style:italic\">getstakingstatus</span>")));
*/
    QString stakeContent =  tr("stakeContent");
    ui->labelContent_Stake->setText(stakeContent);
/*
    QString supportContent = formatFAQContent(
        formatFAQParagraph(
            tr("We have support channels in most of our official chat groups, for example %1")
                .arg("<a style='color: #E42534' href='https://www.sparkbase.io/discord'>" + tr("#support in our Discord") + "</a>.")));
*/
    QString supportContent = tr("supportContent");
    ui->labelContent_Support->setText(supportContent);
/*
    QString masternodeContent = formatFAQContent(
        formatFAQParagraph(
            tr("A masternode is a computer running a full node %1 wallet with a requirement of %2 secured collateral to provide extra services to the network and in return, receive a portion of the block reward regularly. These services include:")
                .arg(PACKAGE_NAME)
                .arg(GUIUtil::formatBalance(clientModel->getMNCollateralRequiredAmount(), BitcoinUnits::SPARKS)) +
            formatFAQUnorderedList(
                formatFAQListItem(tr("A decentralized governance (Proposal Voting)")) +
                formatFAQListItem(tr("A decentralized budgeting system (Treasury)")) +
                formatFAQListItem(tr("Validation of transactions within each block")) +
                formatFAQListItem(tr("Act as an additional full node in the network")))) +
        formatFAQParagraph(
            tr("For providing such services, masternodes are also paid a certain portion of reward for each block. This can serve as a passive income to the masternode owners minus their running cost.")) +
        formatFAQParagraph(
            tr("Masternode Perks:") +
            formatFAQUnorderedList(
                formatFAQListItem(tr("Participate in Sparkbase Governance")) +
                formatFAQListItem(tr("Earn Masternode Rewards")) +
                formatFAQListItem(tr("Commodity option for future sale")) +
                formatFAQListItem(tr("Help secure the Sparkbase network")))) +
        formatFAQParagraph(
            tr("Requirements:") +
            formatFAQUnorderedList(
                formatFAQListItem(tr("%1 per single Masternode instance")
                        .arg(GUIUtil::formatBalance(clientModel->getMNCollateralRequiredAmount(), BitcoinUnits::SPARKS))) +
                formatFAQListItem(tr("Must be stored in a core wallet")) +
                formatFAQListItem(tr("Need dedicated IP address")) +
                formatFAQListItem(tr("Masternode wallet to remain online")))));
*/
    QString masternodeContent = tr("masternodeContent");
    ui->labelContent_Masternode->setText(masternodeContent);
/*
    QString mNControllerContent = formatFAQContent(
        formatFAQParagraph(
            formatFAQParagraph(tr("The Sparkbase app is an innovative portfolio tracker, manager and master available on iOS and Android, which enables you to:")) +

            formatFAQUnorderedList(
              formatFAQListItem(
                tr("Create Your Portfolio")
              ) +
              formatFAQListItem(
                tr("Find Lucrative Assets")
              ) +
              formatFAQListItem(
                tr("Optimize Your Strategy")
              ) +
              formatFAQListItem(
                tr("Add Stocks, Bonds & More")
              )
            ) +
            formatFAQParagraph(tr("Download the Sparkbase app now on iOS or Android.")) +
            formatFAQParagraph(
              tr("Read more at %1")
              .arg("<a style='color: #E42534' href='https://www.sparkbase.io'>" + tr("www.sparkbase.io") + "</a>.")
            )
                    .arg(GUIUtil::formatBalance(clientModel->getMNCollateralRequiredAmount(), BitcoinUnits::SPARKS))));
*/
    QString mNControllerContent = tr("mNControllerContent");
    ui->labelContent_MNController->setText(mNControllerContent);


    // Exit button
    setCssProperty(ui->pushButtonExit, "btn-faq-exit");

    // Web Link
    setCssProperty(ui->pushButtonWebLink, "btn-faq-web");
    setCssProperty(ui->containerButtons, "container-faq-buttons");

    // Buttons
    connect(ui->pushButtonExit, &QPushButton::clicked, this, &SettingsFaqWidget::close);
    connect(ui->pushButton_Intro, &QPushButton::clicked, [this](){onFaqClicked(ui->widget_Intro);});
    connect(ui->pushButton_UnspendableSPARKS, &QPushButton::clicked, [this](){onFaqClicked(ui->widget_UnspendableSPARKS);});
    connect(ui->pushButton_Stake, &QPushButton::clicked, [this](){onFaqClicked(ui->widget_Stake);});
    connect(ui->pushButton_Support, &QPushButton::clicked, [this](){onFaqClicked(ui->widget_Support);});
    connect(ui->pushButton_Masternode, &QPushButton::clicked, [this](){onFaqClicked(ui->widget_Masternode);});
    connect(ui->pushButton_MNController, &QPushButton::clicked, [this](){onFaqClicked(ui->widget_MNController);});

    if (parent)
        connect(parent, &SPARKGUI::windowResizeEvent, this, &SettingsFaqWidget::windowResizeEvent);
}

void SettingsFaqWidget::showEvent(QShowEvent *event)
{
    QPushButton* btn = getButtons()[section];
    QMetaObject::invokeMethod(btn, "setChecked", Qt::QueuedConnection, Q_ARG(bool, true));
    QMetaObject::invokeMethod(btn, "clicked", Qt::QueuedConnection);
}

void SettingsFaqWidget::setSection(Section _section)
{
    section = _section;
}

void SettingsFaqWidget::onFaqClicked(const QWidget* const widget)
{
    ui->scrollAreaFaq->verticalScrollBar()->setValue(widget->y());
}

void SettingsFaqWidget::windowResizeEvent(QResizeEvent* event)
{
    QWidget* w = qobject_cast<QWidget*>(parent());
    this->resize(w->width(), w->height());
    this->move(QPoint(0, 0));
}

std::vector<QPushButton*> SettingsFaqWidget::getButtons()
{
    return {
            ui->pushButton_Intro,
            ui->pushButton_UnspendableSPARKS,
            ui->pushButton_Stake,
            ui->pushButton_Support,
            ui->pushButton_Masternode,
            ui->pushButton_MNController
    };
}

SettingsFaqWidget::~SettingsFaqWidget()
{
    delete ui;
}

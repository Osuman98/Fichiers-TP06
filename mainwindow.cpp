#include "mainwindow.h"

Q_DECLARE_METATYPE(Jeu)
Q_DECLARE_METATYPE(const Jeu*)

MainWindow::MainWindow(GestionnaireJeux* gestionnaire, Utilisateur* utilisateur, QWidget *parent)
    : QMainWindow(parent), gestionnaire_(gestionnaire), utilisateur_(utilisateur)
{
    setup();
}

/// libere la memoire allouer.
MainWindow::~MainWindow()
{
    delete boutique_;
    delete librairieUtilisateur_;
    delete editeurNomJeu_;
    delete editeurPrixJeu_;
    delete editeurFonds_;
    delete boutonAcheterJeu_;
    delete boutonVendreJeu_;
}

/// appelle les methodes d'initialisation de la vue et des connections.
void MainWindow::setup()
{
  setUI();
  chargerJeuxBoutique();
  chargerFonds(utilisateur_->getFonds());
  etablirConnections();
}

/// affiche le jeu selectionner par le click de la souris dans la boutique.
/// correspondant. \param  item  Le jeu cliquee
void MainWindow::selectionnerJeuBoutique(QListWidgetItem* item) {
    Jeu jeu = item->data(Qt::UserRole).value<Jeu>();
    editeurNomJeu_->setText(QString::fromStdString(jeu.getNom()));
    editeurPrixJeu_->setText(QString::number(jeu.getPrix()) + ".00$");
}

/// affiche le jeu selectionner par le click de la souris dans la librairie.
/// correspondant. \param  item  Le jeu cliquee
void MainWindow::selectionnerJeuLibrairie(QListWidgetItem* item) {
    const Jeu* jeu = item->data(Qt::UserRole).value<const Jeu*>();
    editeurNomJeu_->setText(QString::fromStdString(jeu->getNom()));
    editeurPrixJeu_->setText(QString::number(jeu->getPrix()) + ".00$");
}

/// affiche le fond passé en paramètre.
/// correspondant. \param  nouveauFonds  Le nouveau fonds à afficher.
void MainWindow::chargerFonds(unsigned int nouveauFonds) {
    editeurFonds_->setText(QString::number(nouveauFonds));
}

void MainWindow::acheterJeu() {
    const Jeu* jeu = gestionnaire_->chercherJeu(editeurNomJeu_->text().toStdString());
    utilisateur_->acheterJeu(jeu);

    //ajoute le jeu nouvellement acheter dans la vue
    QListWidgetItem* item = new QListWidgetItem(QString::fromStdString(jeu->getNom()), librairieUtilisateur_);
    item->setData(Qt::UserRole, QVariant::fromValue<const Jeu*>(jeu));
}

void MainWindow::vendreJeu() {
    const Jeu* jeu = gestionnaire_->chercherJeu(editeurNomJeu_->text().toStdString());
    utilisateur_->vendreJeu(jeu);
    //retire le jeu de la librairie dans la vue.
    chargerJeuxLibrairie();
}

void MainWindow::etablirConnections() {
    //connect qui lie le click sur un jeu de la boutique avec laffichage des information de ce
    connect(boutique_, SIGNAL(itemClicked(QListWidgetItem*)),
        this, SLOT(selectionnerJeuBoutique(QListWidgetItem*)));

    //todo implémenter tout les connect ici.
}



void MainWindow::setUI() {

    //on commence par créer tout les objets de la vue et les initialiser

    //liste qui contient tout les jeux possible à acheté avec son label
    QLabel* labelBoutique = new QLabel;
    labelBoutique->setText("Boutique : ");

    boutique_ = new QListWidget(this);
    boutique_->setSortingEnabled(true);

    //information sur le jeu selectionner
    // creation label titre
    QLabel* labelJeu = new QLabel;
    labelJeu->setText("Jeu selectionné : ");

    // creation label du nom du jeu
    QLabel* labelNomJeu = new QLabel;
    labelNomJeu->setText("Nom du jeu : ");

    //on ne peut pas modifer le nom du jeu
    editeurNomJeu_ = new QLineEdit;
    editeurNomJeu_->setDisabled(true);

    //layout pour avoir le nom et l'editeur sur une meme ligne.
    QHBoxLayout* layoutNom = new QHBoxLayout;
    layoutNom->addWidget(labelNomJeu);
    layoutNom->addWidget(editeurNomJeu_);

    //TODO  --- creer label du prix du jeu

    //on ne peut pas modifer le prix du jeu
    editeurPrixJeu_ = new QLineEdit;
    editeurPrixJeu_->setDisabled(true);

#   //TODO --- remplir le layout pour avoir le nom et l'editeur sur une meme ligne.
    QHBoxLayout* layoutPrix = new QHBoxLayout;

    //TODO --- creer le bouton pour acheter le jeu

    //TODO --- creer le bouton pour vendre le jeu

    //TODO --- remplir le layout pour que les boutons soient placer ensemble
    QHBoxLayout* layoutBoutons = new QHBoxLayout;

    //ligne pour separer les information du jeu et la librairie de l'utilisateur.
    QFrame* horizontaleFrameLine = new QFrame;
    horizontaleFrameLine->setFrameShape(QFrame::HLine);


    //label et editeur pour les fonds de l'utilisateurs
    QLabel* labelFonds = new QLabel;
    labelFonds->setText("Fonds : ");

    //empeche de modifier les fonds
    editeurFonds_ = new QLineEdit;
    editeurFonds_->setDisabled(true);
    editeurFonds_->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Preferred);

    //label pour presenter la librairie de l'utilisateur
    QLabel* labelLibrairieUtilisateur = new QLabel;
    labelLibrairieUtilisateur->setText("Votre librairie : ");

    //layout pour avoir les fond et le label librarie sur la meme ligne
    QHBoxLayout* layoutFonds = new QHBoxLayout;
    layoutFonds->addWidget(labelLibrairieUtilisateur, 0, Qt::AlignLeft);
    layoutFonds->addWidget(labelFonds, 0, Qt::AlignRight);
    layoutFonds->addWidget(editeurFonds_, 0, Qt::AlignRight);

    //liste de tout les jeu que l'utilisateur à acheté
    librairieUtilisateur_ = new QListWidget(this);
    librairieUtilisateur_->setSortingEnabled(true);

    //une fois que tout les objets sont créés et initialiés, on peut les disposer dans l'écran selon un layout qui nous convient

    //application en 2 section (layout gauche et droite)
    QVBoxLayout* layoutGauche = new QVBoxLayout;
    layoutGauche->addWidget(labelBoutique);
    layoutGauche->addWidget(boutique_);

    // TODO --- Remplir le layout droite
    QVBoxLayout* layoutDroite = new QVBoxLayout;
    layoutDroite->addWidget(labelJeu);


    //main layout qui contient tout
    QHBoxLayout* mainLayout = new QHBoxLayout;
    mainLayout->addLayout(layoutGauche);
    mainLayout->addLayout(layoutDroite);

    QWidget* widget = new QWidget;
    widget->setLayout(mainLayout);
    setCentralWidget(widget);

    setWindowTitle("Poly Store");
}

/// affiche les jeu de la boutique
void MainWindow::chargerJeuxBoutique() {
    boutique_->clear();
    for (Jeu jeu : gestionnaire_->getJeux()) {
        QListWidgetItem* item = new QListWidgetItem(QString::fromStdString(jeu.getNom()), boutique_);
        item->setData(Qt::UserRole, QVariant::fromValue<Jeu>(jeu));
    }
}

/// affiche les jeu de la librairie de l'utilisateur
void MainWindow::chargerJeuxLibrairie() {
    librairieUtilisateur_->clear();
    for (const Jeu* jeu : utilisateur_->getJeux()) {
        QListWidgetItem* item = new QListWidgetItem(QString::fromStdString(jeu->getNom()), librairieUtilisateur_);
        item->setData(Qt::UserRole, QVariant::fromValue<const Jeu*>(jeu));
    }

}

/// affiche le message passer en parametre.
/// correspondant. \param  msg  Le message afficher
void MainWindow::afficherMessage(QString msg) {
    QMessageBox mbox;
    mbox.setText(msg);
    mbox.exec();
}



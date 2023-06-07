CREATE TABLE Olimpiada (
    Ano    NUMERIC(4)      NOT NULL,
    Sede   VARCHAR(3)      NOT NULL,
    CONSTRAINT pk_olimpiada PRIMARY KEY (Ano)
);

CREATE TABLE Tocha (
    Ano        	          NUMERIC(4)     NOT NULL,
    Codigo                NUMERIC(6)     NOT NULL,
    CpfDesigner           VARCHAR(14)    NOT NULL,
    QuantidadeDeLocais    NUMERIC(3)     NULL,
    CONSTRAINT pk_tocha PRIMARY KEY (Ano, Codigo)
);

CREATE TABLE Mascote (
    Ano       	   NUMERIC(4)     NOT NULL,
    CpfCriador     VARCHAR(14)    NOT NULL,
    Descricao      VARCHAR(600)   NULL,
    Nome           VARCHAR(100)   NOT NULL,
    CONSTRAINT pk_mascote PRIMARY KEY (Ano, Nome)
);

CREATE TABLE Logo (
    Ano       	   NUMERIC(4)     NOT NULL,
    CpfCriador     VARCHAR(14)    NOT NULL,
    Descricao      VARCHAR(600)   NULL,
    Nome           VARCHAR(100)   NULL,
    CONSTRAINT pk_logo PRIMARY KEY (Ano, Nome)
);

CREATE TABLE Pessoa (
    AnoNasc     	NUMERIC(4)     NULL,
    DiaNasc     	NUMERIC(2)     NULL,
    MesNasc     	NUMERIC(2)     NULL,
    CPF    		    VARCHAR(14)    NOT NULL,
    Pais            VARCHAR(3)     NOT NULL,
    PrimeiroNome    VARCHAR(100)   NOT NULL,
    Sobrenome    	VARCHAR(200)   NULL,
    Sexo            VARCHAR(1)     NOT NULL,
    CONSTRAINT pk_pessoa PRIMARY KEY (CPF),
    CONSTRAINT ck_sexo_pessoa CHECK (Sexo='M' or Sexo='F')
);

CREATE TABLE Atleta (
    CPF    		           VARCHAR(14)    NOT NULL,
    CodMedalhista     	   NUMERIC(6)     NULL,
    QuantidadeMedalhas     NUMERIC(4)     NULL,
    CONSTRAINT pk_atleta   PRIMARY KEY (CPF)

);

CREATE TABLE Equipe (
    Abreviacao             VARCHAR(3)     NOT NULL,
    Nome             	   VARCHAR(100)   NULL,
    CodMedalhista          NUMERIC(6)     NULL,
    CONSTRAINT pk_equipe   PRIMARY KEY (Abreviacao)
);

CREATE TABLE Podio (
    CodProva               NUMERIC(6)     NOT NULL,
    CodMedalhista          NUMERIC(6)     NOT NULL,
    CONSTRAINT pk_podio    PRIMARY KEY (CodProva,CodMedalhista)
);

CREATE TABLE Medalhista (
    CodMedalhista          NUMERIC(6)     NOT NULL,
    CONSTRAINT pk_medalhista    PRIMARY KEY (CodMedalhista)
);

CREATE TABLE Modalidade (
    Nome             	   VARCHAR(100)    NULL,
    Codigo       	       NUMERIC(6)      NOT NULL,
    Sexo                   VARCHAR(1)      NOT NULL,
    CONSTRAINT pk_modalidade   PRIMARY KEY (Codigo),
    CONSTRAINT ck_sexo_modalidade CHECK (Sexo='M' or Sexo='F')
);

CREATE TABLE Prova (
    Codigo     	        NUMERIC(6)     NOT NULL,
    CodModalidade       NUMERIC(6)     NOT NULL,
    Descrição     	    VARCHAR(600)   NULL,
    DataDia    		    NUMERIC(2)     NOT NULL,
    DataMes             NUMERIC(2)     NOT NULL,
    DataMinuto    	    NUMERIC(2)     NOT NULL,
    DataHoras    	    NUMERIC(2)     NOT NULL,
    Fase       	        VARCHAR(30)    NULL,
    CONSTRAINT pk_prova    PRIMARY KEY (Codigo)
   
);

CREATE TABLE Pais (
    Abreviacao     	VARCHAR(3)       NOT NULL,
    Continente      VARCHAR(30)      NOT NULL,
    NomeOficial    	VARCHAR(200)     NULL,
    NomeComum    	VARCHAR(100)     NULL,
    CONSTRAINT pk_pais    PRIMARY KEY (Abreviacao)
);

CREATE TABLE Continente (
    Nome     	        VARCHAR(20)     NULL,
    Cor                 VARCHAR(30)    NOT NULL,
    QuantidadePaises    NUMERIC(2)     NULL,
    CONSTRAINT pk_continente PRIMARY KEY (Cor),
    CONSTRAINT ck_cor_continente CHECK (Cor= 'Azul' or Cor= 'Vermelho' or Cor= 'Verde' or Cor= 'Amarelo' or Cor= 'Preto')
);


CREATE TABLE Embaixadores (
	Ano                      NUMERIC(4)      NOT NULL,
    CpfEmbaixador     	     VARCHAR(14)     NOT NULL,
    CodTocha                 NUMERIC(4)      NOT NULL,
    CONSTRAINT pk_embaixadores    PRIMARY KEY (CpfEmbaixador, CodTocha)
);


CREATE TABLE ProvasAtletas (
    CodProva    	     NUMERIC(4)     NOT NULL,
    CpfAtleta            VARCHAR(14)    NOT NULL,
    CONSTRAINT pk_provas_atletas    PRIMARY KEY (CodProva, CpfAtleta)
);

CREATE TABLE EquipesAtletas (
    AbrevEquipe    	     VARCHAR(3)     NOT NULL,
    CpfAtleta            VARCHAR(14)    NOT NULL,
    CONSTRAINT pk_equipe_atletas    PRIMARY KEY (AbrevEquipe, CpfAtleta)
);

CREATE TABLE PodioMedalhistas (
    Posicao    	     NUMERIC(4)     NOT NULL,
    CodMedalhista    NUMERIC(6,1)   NOT NULL,
    CodProva	     NUMERIC(4)     NOT NULL,
    CONSTRAINT pk_podio_medalhistas    PRIMARY KEY (CodMedalhista, CodProva)
);

CREATE TABLE ProvasEquipes (
    AbrevEquipe      VARCHAR(3)     NOT NULL,
    CodProva	     NUMERIC(6)     NOT NULL,
    CONSTRAINT pk_provas_equipes    PRIMARY KEY (CodProva,AbrevEquipe)
);

CREATE TABLE OlimpiadaPais(
    AnoOlimpiada   	     NUMERIC(4)     NOT NULL,
    AbreviacaoPais	     VARCHAR(3)     NOT NULL,
    NumeroDeAtletas	     NUMERIC(4)     NULL,
    NumeroDeMedalhas	 NUMERIC(4)     NULL,
    CONSTRAINT pk_pais_olimpiada    PRIMARY KEY (AnoOlimpiada,AbreviacaoPais)
);

/* azul: Europa, 
amarelo: Ásia, 
preto: África, 
verde: Oceania e 
vermelho: as Américas. */

INSERT INTO Pais
VALUES ('EUA', 'Vermelho', 'Estados Unidos da América', 'Estados Unidos');
INSERT INTO Pais
VALUES ('RUS', 'Azul', 'Federação Russa', 'Rússia');
INSERT INTO Pais
VALUES ('ALE', 'Azul', 'República Federal da Alemanha', 'Alemanha');
INSERT INTO Pais
VALUES ('GBR', 'Azul', 'Reino Unido da Grã-Bretanha', 'Grã-Bretanha');
INSERT INTO Pais
VALUES ('CHI', 'Amarelo', 'República Popular da China', 'China');
INSERT INTO Pais
VALUES ('FRA', 'Azul', 'República Francesa', 'França');
INSERT INTO Pais
VALUES ('ITA', 'Azul', 'República Italiana', 'Itália');
INSERT INTO Pais
VALUES ('SWE', 'Azul', 'Reino da Suécia', 'Suécia');
INSERT INTO Pais
VALUES ('NOR', 'Azul', 'Reino da Noruega', 'Noruega');
INSERT INTO Pais
VALUES ('JPN', 'Amarelo', 'Japão', 'Japão');
INSERT INTO Pais
VALUES ('AUS', 'Verde', 'Comunidade da Austrália', 'Austrália');
INSERT INTO Pais
VALUES ('CAN', 'Vermelho', 'Canadá', 'Canadá');
INSERT INTO Pais
VALUES ('KEN', 'Preto', 'República do Quênia', 'Quênia');
INSERT INTO Pais
VALUES ('GRE', 'Azul', 'República Helénica', 'Grécia');
INSERT INTO Pais
VALUES ('RSA', 'Preto', 'República da África do Sul', 'África do Sul');
INSERT INTO Pais
VALUES ('NZL', 'Verde', 'Nova Zelândia', 'Nova Zelândia');
INSERT INTO Pais
VALUES ('KOR', 'Amarelo', 'República da Coreia', 'Coréia do Sul');
INSERT INTO Pais
VALUES ('ARG', 'Vermelho', 'República Argentina', 'Argentina');
INSERT INTO Pais
VALUES ('NED', 'Azul', 'Reino dos Países Baixos', 'Países Baixos');

INSERT INTO Continente VALUES ('Europa', 'Azul', 44);

INSERT INTO Continente VALUES ('Ásia', 'Amarelo', 48);

INSERT INTO Continente VALUES ('África', 'Preto', 54);

INSERT INTO Continente VALUES ('Oceania', 'Verde', 14);

INSERT INTO Continente VALUES ('Américas', 'Vermelho', 35);

ALTER TABLE Tocha
ADD CONSTRAINT fk_tocha_designer FOREIGN KEY (CpfDesigner) REFERENCES Pessoa (CPF);

ALTER TABLE Tocha
ADD CONSTRAINT fk_tocha_ano FOREIGN KEY (Ano) REFERENCES Olimpiada (Ano);

ALTER TABLE Mascote
ADD CONSTRAINT fk_mascote_criador FOREIGN KEY (CpfCriador) REFERENCES Pessoa (CPF);

ALTER TABLE Mascote
ADD CONSTRAINT fk_mascote_ano FOREIGN KEY (Ano) REFERENCES Olimpiada (Ano);

ALTER TABLE Logo
ADD CONSTRAINT fk_logo_criador FOREIGN KEY (CpfCriador) REFERENCES Pessoa (CPF);

ALTER TABLE Logo
ADD CONSTRAINT fk_logo_ano FOREIGN KEY (Ano) REFERENCES Olimpiada (Ano);

ALTER TABLE Pessoa
ADD CONSTRAINT fk_pessoa_pais FOREIGN KEY (Pais) REFERENCES Pais (Abreviacao);

ALTER TABLE Atleta
ADD CONSTRAINT fk_atleta_pessoa FOREIGN KEY (CPF) REFERENCES Pessoa (CPF) ON DELETE CASCADE;

ALTER TABLE Atleta
ADD CONSTRAINT fk_atleta_medalhista FOREIGN KEY (CodMedalhista) REFERENCES Medalhista (CodMedalhista);

ALTER TABLE Equipe
ADD CONSTRAINT fk_equipe_medalhista FOREIGN KEY (CodMedalhista) REFERENCES Medalhista (CodMedalhista);

ALTER TABLE Podio
ADD CONSTRAINT fk_podio_medalhista FOREIGN KEY (CodMedalhista) REFERENCES Medalhista (CodMedalhista);

ALTER TABLE Podio
ADD CONSTRAINT fk_podio_prova FOREIGN KEY (CodProva) REFERENCES Prova (Codigo);

ALTER TABLE Prova
ADD CONSTRAINT fk_prova_modalidade FOREIGN KEY (CodModalidade) REFERENCES Modalidade (Codigo);

ALTER TABLE Pais
ADD CONSTRAINT fk_pais_continente FOREIGN KEY (Continente) REFERENCES Continente (Cor);

ALTER TABLE Embaixadores
ADD CONSTRAINT fk_embaixador_pessoa FOREIGN KEY (CpfEmbaixador) REFERENCES Pessoa (CPF);

ALTER TABLE Embaixadores
ADD CONSTRAINT fk_ano FOREIGN KEY (Ano) REFERENCES Olimpiada (Ano);

ALTER TABLE Embaixadores
ADD CONSTRAINT fk_embaixador_tocha FOREIGN KEY (CodTocha, Ano) REFERENCES Tocha (Codigo, Ano);

ALTER TABLE ProvasAtletas
ADD CONSTRAINT fk_prova_codigo FOREIGN KEY (CodProva) REFERENCES Prova (Codigo);

ALTER TABLE ProvasAtletas
ADD CONSTRAINT fk_prova_cpf FOREIGN KEY (CpfAtleta) REFERENCES Atleta (CPF);

ALTER TABLE EquipesAtletas
ADD CONSTRAINT fk_equipe_abrev FOREIGN KEY (AbrevEquipe) REFERENCES Equipe (Abreviacao);

ALTER TABLE EquipesAtletas
ADD CONSTRAINT fk_equipe_atleta FOREIGN KEY (CpfAtleta) REFERENCES Atleta (CPF);

ALTER TABLE PodioMedalhistas
ADD CONSTRAINT fk_podio_medalhista FOREIGN KEY (CodMedalhista) REFERENCES Medalhista (CodMedalhista);

ALTER TABLE PodioMedalhistas
ADD CONSTRAINT fk_podio_prova FOREIGN KEY (CodProva) REFERENCES Prova (Codigo);

ALTER TABLE ProvasEquipes
ADD CONSTRAINT fk_prova_cod FOREIGN KEY (CodProva) REFERENCES Prova (Codigo);

ALTER TABLE ProvasEquipes
ADD CONSTRAINT fk_prova_abrev FOREIGN KEY (AbrevEquipe) REFERENCES Equipe(Abreviacao);
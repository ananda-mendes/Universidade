const { Pool } = require('pg');
const V = require('./variables');

const DATABASE_URL = `postgres://${V.db_username}:${V.db_password}@${V.host}:${V.port}/${V.db_name}`;

// ==> Conexão com a Base de Dados:
const pool = new Pool({
  connectionString: DATABASE_URL
});

pool.on('connect', () => {
  console.log('Base de Dados conectado com sucesso!');
});

module.exports = {
  query: (text, params) => pool.query(text, params),
};
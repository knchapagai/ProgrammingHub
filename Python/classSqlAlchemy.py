from sqlalchemy import create_engine
import pandas as pd

class SqlalchemyOop:
    def return_engine(self, connection_string):
        engine = create_engine(connection_string)
        connection = engine.connect()
        return connection

    def database_connection(self, connection):
        connection = self.engine.connect()

    def select_query(self, query):
        data = pd.read_sql(query, self.connection)
        return data

    def get_tables(self):
        return self.engine.table_names()

# independant
    @staticmethod
    def df(data):
        df = pd.DataFrame(data)
        return df

    def get_duplicates(self):
        z = self.df
        y = z.copy()
        analysis_abc = pd.concat([z, y])
        analysis_abc.to_sql('analysis_abc', con=self.engine)
        self.connection.close()

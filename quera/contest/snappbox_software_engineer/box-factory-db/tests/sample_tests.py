import unittest

from sql_judge_utils.mysql import MysqlDatabase as Database
from sql_judge_utils.parser import get_queries


class SampleTests(unittest.TestCase):

    @classmethod
    def setUpClass(cls):
        cls.submission_path = 'queries.sql'
        cls.submission_queries = get_queries(cls.submission_path)
        cls.valid_queries = [
            '''
                SELECT 3 AS id
                UNION ALL
                SELECT 4
                UNION ALL
                SELECT 5
                UNION ALL
                SELECT 8
            ''',
            '''
                SELECT 4787106.00
            ''',
            '''
                SELECT 6 AS rate_avg
                UNION ALL
                SELECT 2
                UNION ALL
                SELECT 9
                UNION ALL
                SELECT 8
                UNION ALL
                SELECT 4
                UNION ALL
                SELECT 7
                UNION ALL
                SELECT 10
                UNION ALL
                SELECT 1
                UNION ALL
                SELECT 5
                UNION ALL
                SELECT 3
            ''',
            '''
                SELECT 4 AS id, 10 AS driver_id
                UNION ALL
                SELECT 42, 2
                UNION ALL
                SELECT 59, 6
                UNION ALL
                SELECT 70, 3
                UNION ALL
                SELECT 74, 4
                UNION ALL
                SELECT 92, 5
            ''',
            '''
                SELECT ' xtmjkMW' AS name, '+989707173773' AS phone
                UNION ALL
                SELECT 'alilubOaXC', '+989347921701'
                UNION ALL
                SELECT 'alilyopz0Y0SLBO', '+989300249471'
                UNION ALL
                SELECT 'aliv7jL3cMOuB29x1', '+989462565663'
                UNION ALL
                SELECT 'EgYYltI', '+989750299436'
                UNION ALL
                SELECT 'l5IkRbO', '+989609625336'
                UNION ALL
                SELECT 'vczXwJucq149Zy', '+989164562757'
            '''
        ]
        cls.db1 = Database('db1')
        cls.db2 = Database('db2')

        for db in [cls.db1, cls.db2]:
            db.drop()
            db.create()
            db.initf('tests/sample_initial.sql')

    def _run_test(self, index: int):
        valid_query = self.valid_queries[index]
        submission_query = self.submission_queries[index]
        status, message = False, ''

        col_names_1, records_1 = self.db1.run_query(valid_query)
        col_names_2, records_2 = self.db2.run_query(submission_query)
        status, message = Database.compare_query_result(
            col_names_1,
            records_1,
            col_names_1,
            records_2
        )
        print(f"test#{index + 1} - status: {status} - message: {message}\n"
              f"col_names_1, records_1, col_names_1, records_2:\n"
              f"{col_names_1, records_1, col_names_1, records_2}")

        self.assertTrue(status, message)
        self.assertEqual(message, '')

    def test_query_1(self):
        self._run_test(0)

    def test_query_2(self):
        self._run_test(1)

    def test_query_3(self):
        self._run_test(2)

    def test_query_4(self):
        self._run_test(3)

    def test_query_5(self):
        self._run_test(4)

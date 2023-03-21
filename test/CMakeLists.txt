# GoogleTest
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.12.1
)
FetchContent_MakeAvailable(googletest)


set(RUN_TESTS
  # TODO Add test files
  # foo_test.cc
  # swea_1206_view.cc
  # swea_1215_palindrome.cc
  # swea_1240_simp_bin_password.cc
  # swea_1219_search_path.cc
  # swea_1221_gns.cc
  # jgol_1733_omok.cc
  # jgol_2194_yogurt.cc
  # jgol_1295_binsearch.cc
  # jgol_1374_addsub.cc
  # swea_1244_win_prize.cc
  # swea_1244_win_prize_str.cc
  # swea_1265_talent2.cc
  # swea_1266_comp_prod.cc
  # swea_1218_paren.cc
  # swea_1234_password.cc
  # jgol_3572_postfix.cc
  # swea_1225_encryp.cc
  # swea_1245_balance.cc
  # swea_1256_kth_suffix.cc
  # swea_1257_kth_str.cc
  # jgol_1620_phonenum.cc
  # swea_10804_mirror.cc
  # swea_1211_ladder2.cc
  # swea_1227_maze2.cc
  # jgol_1695_areanum.cc
  # jgol_1078_juggling.cc
  # swea_1267_workseq.cc
  # swea_1249_supply.cc
  # jgol_1462_treasure.cc
  # jgol_1060_mst.cc
  # swea_1251_hanaro.cc
  # swea_1849_binscale.cc
  # swea_1231_inorder.cc
  # swea_1248_ancestor.cc
  # jgol_1726_max_in_range.cc
  # jgol_3142_id_check.cc
  # jgol_2613_tomato.cc
  # jgol_2058_hedgehog.cc
  swea_1247_opt_path.cc
  # jgol_1889_nqueen.cc
  # jgol_1662_bishop.cc
)

add_executable(run_test ${RUN_TESTS})

target_link_libraries(
  run_test 
  gtest_main
)

include(GoogleTest)
gtest_discover_tests(run_test)
